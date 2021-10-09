import cv2
from flask import Flask, render_template, Response, request
from flask_wtf import FlaskForm, SubmitField
from hand_cricket import VideoCamera
app = Flask(__name__, template_folder='D:/Virtual-Hand-Cricket/api/templates')

class SubmitForm(FlaskForm):
    submit = SubmitField('h')
@app.route('/')
def index():
    # Main page
    return render_template('index.html')
def gen_game(key,hand_cricket):
    
    """Video streaming generator function."""
    while True:
        frame= hand_cricket.get_frame(key)
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n\r\n')
    
@app.route('/game', methods=['GET','POST'])
def game():
    form = SubmitForm()
    
    if form.validate_on_submit():
        if form.submit.data:
            return Response(gen_game(key,VideoCamera()), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == '__main__':
    app.run(debug=False,threaded=False)