#Program to Convert Text to Speech
'''
Using Pyttsx3 module to convert text-to-speech
pyttsx3 uses Windows API to convert text-to-speech
'''

import pyttsx3

engine = pyttsx3.init('sapi5')                  #spai5 is a Windows API that collects the vocies available in our PC
voices = engine.getProperty('voices')           #getProperty get the voices from the PC 
engine.setProperty('voice',voices[1].id)        #setProperty set the property of voices that we want 
                                                #basically there are 2 voices one of Male(Daivd) / Female(Zira)
#define speak method
def speak(audio):
    print(audio)
    engine.say(audio)
    engine.runAndWait()
    
#calling speak function
speak("Follow to Prathmesh Chaudhari on Instagram. ID given Below")     
