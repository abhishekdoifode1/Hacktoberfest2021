import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init('sapi5')  #Microsoft speach API to take voices.
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)

name = 'Vritika'

def speak(audio):
    engine.say(audio) 
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if(hour>=0 and hour<12):
        speak('Good Morning '+name)
    elif(hour>12 and hour<18):
        speak('Good Afternoon '+name)
    else:
        speak('Good Evening '+name)

    speak('I am your assistant, please tell me how may i help you')


def takeCommand():
    #It takes microphone input from the user and returns String output.
    r = sr.Recognizer()

    with sr.Microphone() as source: #Taking microphone as my source.
        print('Listening...')
        r.pause_threshold = 1 
        #seconds of non speaking audio before a phrase is considered complete.
        #I.e if ia take a gap of one second during my speaking it should not consider my phrease is complete.
        audio = r.listen(source)

    try:
        print('Recognizing...')
        query = r.recognize_google(audio,language='en-in')#Speech recognition. converts speech to text.
        print('User said: ',query)

    except Exception as e:
        print(e)
        print('Say that again please...')
        return 'None'

    return query

def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.login('vritikamalhotra23@gmail.com','haha6264') 
    #If you wish to make it work. Try to store your password in a text file and read data from it.
    server.sendmail('vritikamalhotra23@gmail.com',to,content)
    server.close()



if __name__ == "__main__":
    wishMe()
    while True:
        #query = takeCommand().lower()

        query = input('Enter your query : ')
        print(query)

        #Logic for executing taska based upon query.

        if('wikipedia' in query):
            speak('Searching Wikipedia...')
            query = query.replace('wikipedia','')
            results = wikipedia.summary(query, sentences=2)
            speak('According to wikipedia')
            speak(results)

        elif('open youtube' in query):
            webbrowser.open('youtube.com')

        elif('coursera' in query):
            webbrowser.open('https://www.coursera.org/programs/lj-institute-of-engineering-and-technology-on-coursera-hg62a')
        
        elif('google' in query):
            webbrowser.open('google.com')

        elif('stackoverflow' in query):
            webbrowser.open('stackoverflow.com')

        elif('play music' in query):
            music_dir = ''
            songs = os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[0]))

        elif('time' in query):
            strtime = datetime.datetime.now().strftime("%H:%M:%S")
            speak('The time is '+strtime)

        elif('android studio' in query):
            codePath = "C:\\Program Files\\Android\\Android Studio\\bin\\studio64.exe"
            os.startfile(codePath)

        elif('who are you' in query):
            speak('I am a robot created by Vritika. I am made to manage Vritikas desktop')
        
        elif('name' in query):
            speak('My name is Emma. How are you')

        elif('I' in query):
            speak('Thats great')

        elif('thankyou' in query):
            speak('It was a pleasure to work with you')

        elif('email to vritika' in query):
            try:
                speak('What should i say')
                content = takeCommand() #Recognises whatever we want to send
                to = 'vritikamalhotra23@gmail.com'
                sendEmail(to,content)
                speak('Email has been sent to vritika')

            except Exception:
                speak('Sorry vritika I am not able to send the email')

        else:
            speak('I am a robot still in development phase but i would like to help you with this when i am completely programmedt')

        


