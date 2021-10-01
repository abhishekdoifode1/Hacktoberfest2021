import speedtest

st = speedtest.Speedtest()
print(f"Download Speed : {st.download()}") 
print(f"Upload Speed : {st.upload()}")
