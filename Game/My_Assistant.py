import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import os
import smtplib
import random

engine = pyttsx3.init('sapi5')   #  to take voice..
voices = engine.getProperty('voices')
for x in range(1,12):
    print(voices[x])
engine.setProperty('voice',voices[10].id)        #For    English -> 2,4,6,8    ,         for Hindi -> 10 11

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour= int(datetime.datetime.now().hour)

    if  hour>=0 and hour<12:
        speak("Good Morning!")

    elif hour>=12 and hour<18:
        speak("Good Afternoon!")

    else :
        speak("चुतुपर्णा चुत चाटकर")
        speak("")
    speak("I am your assistant बहन के लाओदे, Could you please tell how, may I help you ?? ")

def takeCommand():  #take input from mic to text(string))

    r = sr.Recognizer()
    with sr.Microphone() as Source:
        print("Yes ...Listening....")
        r.pause_threshold = 1  # to increase time....
        audio = r.listen(Source)

    try: 
        print("Recognising.....")
        query= r.recognize_google(audio,language='en-in')
        print(f"User said  ::   {query}\n")
    except Exception as e:
        print(e)
        print("High surrounding voice, Say that again please !!")
       # speak("क्या आप फिर से बोलेंगे, हम समज नहीं पायें आप क्या बोले, please repeat")
        return "None"
    return query


# important mail function

def sendEmail(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()
    server.login('harshit.singh@iiitg.ac.in', 'evsuhs@00')
    server.sendmail('harshit.singh@iiitg.ac.in', to, content)
    server.close()
if __name__=="__main__":

   # speak("नमस्कार कैसे है आप , हम बिहार के सहायक है, आप के लिए हम क्या कर सकते हैं")

    wishMe()
    
    x=3
    while(x):
        x-1
        y=random.randint(0,3)
        z=random.randint(0,3)
        k=random.randint(0,4)
        query = takeCommand().lower() #Converting user query into lower case
        # Logic for executing tasks based on query
        
        
        if 'wikipedia' in query:  #if wikipedia found in the query then this block will be executed
            speak('Searching Wikipedia...')
            query = query.replace("wikipedia", "")
            results = wikipedia.summary(query, sentences=2) 
            speak("According to Wikipedia")
            speak(results)
        elif 'youtube' in query:
            webbrowser.open("youtube.com")
        elif 'google' in query:
            webbrowser.open("google.com")
        elif 'my github' in query:
            webbrowser.open ("github.com/HarshitSingh-14")
        elif 'github' in query:
            webbrowser.open ("github.com")        
        elif 'stack overflow' in query:
            webbrowser.open("stackoverflow.com")
        
        
            
        elif 'all certificate' in query:
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[0]))
            
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[1]))
            
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[2]))
            
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[3]))       

            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[4]))       

            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[5]))       

            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[6]))       

            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[7]))       




        elif 'any certificate' in query:
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[k]))

        
        elif 'certificate' in query:
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\c'
            songs= os.listdir(music_dir)
            print(songs)
            os.startfile(os.path.join(music_dir,songs[k]))        
        
        
        elif 'family' in query:
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\fm'
            songs= os.listdir(music_dir)
            print(songs)
            
            os.startfile(os.path.join(music_dir,songs[y]))
    
        elif 'friend' in query:
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\fr'
            songs= os.listdir(music_dir)
            print(songs)
            
            os.startfile(os.path.join(music_dir,songs[z]))    

        elif 'vocabulary' in query:
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\book'
            songs= os.listdir(music_dir)
            print(songs)
            
            os.startfile(os.path.join(music_dir,songs[0]))
        
        elif 'book' in query:
            music_dir = 'C:\\Users\\Admin\\Downloads\\open\\book'
            songs= os.listdir(music_dir)
            print(songs)
            
            os.startfile(os.path.join(music_dir,songs[0]))


        elif 'time' in query:
            strTime= datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"Sir, the time now is {strTime}")

        elif 'repeat' in query:
            q=takeCommand().lower()
            speak(q)

        elif 'email to harshit' in query:   
            try:
                speak("Go on , What shouldI  say  to him?")
                content = takeCommand()
                to = "harshitsingh14@gmail.com"
                sendEmail(to, content)
                speak("Email has been sent")

            except Exception as e:
                print(e)
                speak("Sorry my friend, Harshit. I am not able to send this EMAIL")

        elif 'bye' in query: 
            speak('Thank you, it was nice talking to you !!!')
            break

        elif 'leave' in query: 
            speak('Thank you, it was nice talking to you !!!')
            break
        elif 'a******' in query:
            speak('I believe in tit for tat, if I good to you, please be good to me')
        elif 'f***' in query:
            speak('I do not accept this from you, if I am good to you, please be good to me')

