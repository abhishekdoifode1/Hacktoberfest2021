import pyttsx3 #pip install pyttsx3
import speech_recognition as sr #pip install speechRecognition
import datetime
import wikipedia #pip install wikipedia
import webbrowser
import os
import smtplib
import pyautogui
import psutil

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[1].id)
engine.setProperty('voice', voices[0].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good Morning sir!")

    elif hour>=12 and hour<18:
        speak("Good Afternoon sir!")   

    else:
        speak("Good Evening sir!")  

    speak("Hello I am Jarvis. speed one terabite, cpu 12ssr4. Please tell me how may I help you")       

def takeCommand():
    #It takes microphone input from the user and returns string output

    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")    
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except Exception as e:
        # print(e)    
        print("Say that again please...")  
        return "None"
    return query

def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('youremail@gmail.com', 'your-password')
    server.sendmail('youremail@gmail.com', to, content)
    server.close()

def screenshot():
    img = pyautogui.screenshot()
    img.save("C:\\Users\\Aritro chakraborty\\Desktop\\ss.png")

def cpu():
    usage = str(psutil.cpu_percent())
    speak('cpu is usage at' + usage +"GB")
def battery():
    battery = psutil.sensors_battery()
    speak("Battery is percentage is")
    speak(battery.percent)

if __name__ == "__main__":
    wishMe()
    while True:
    # if 1:
        query = takeCommand().lower()

        # Logic for executing tasks based on query
        if 'wikipedia' in query:
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2)
            speak("According to Wikipedia")
            print(results)
            speak(results)

        elif 'open youtube' in query:
            webbrowser.open("youtube.com")

        # elif 'open google' in query:
        #     speak('what should i search..!')
        #     edge ='C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe %s'
        #     search = takeCommand().lower()
        #     webbrowser.get(edge).open_new_tab(search+'.com')

        elif 'open google' in query:
            webbrowser.open("google.com")

        elif 'open stack overflow' in query:
            webbrowser.open("stack overflow.com")

        elif 'remember that' in query:
            speak("What shpuld i remember ? ")   
            data = takeCommand()
            speak("you said me to remember that"+data)
            remember = open('data.txt','w')
            remember.write(data)
            remember.close()

        elif 'do you know anything' in query:
            remember = open('data.txt','r')
            speak("you said me to remember that" +remember.read())

        elif 'play music' in query:
            music_dir = 'D:\\Favorite Songs2'
            songs = os.listdir(music_dir)
            print(songs)    
            os.startfile(os.path.join(music_dir, songs[0]))

        elif "cpu" in query:
            cpu()

        elif "battery" in query:
            battery()

        elif 'time' in query:
            strTime = datetime.datetime.now().strftime("%H:%M:%S")    
            speak(f"Sir, the time is {strTime}")

        elif 'thank you' in query:   
            speak("it's my pleasure sir..")

        elif 'screenshot' in query:
            speak("taking ..")
            screenshot()
            speak("it's done sir ! please check it in desktop..")

        elif 'open code' in query:
            codePath = 'C:\\Users\\Aritro chakraborty\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe'
            os.startfile(codePath)

        elif 'date' in query:
            year = int(datetime.datetime.now().year)
            month = int(datetime.datetime.now().month)
            date = int(datetime.datetime.now().day)
            speak("Today is")
            speak(date)
            speak(month)
            speak(year)

        elif 'offline' in query:
            speak("going to offline.. i was happy to help you..")
            quit()

        elif 'email' in query:
            try:
                speak("What should I say?")
                content = takeCommand()
                to = "harryyourEmail@gmail.com"    
                sendEmail(to, content)
                speak("Email has been sent!")
            except Exception as e:
                print(e)
                speak("i am extremly Sorry sir. I am not able to send this email")    
