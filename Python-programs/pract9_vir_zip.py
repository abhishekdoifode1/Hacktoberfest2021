import dpkt
import socket
def findDownload(pcap):
    for(ts, buf) in pcap:
        try:
            eth= dpkt.ethernet.Ethernet(buf)
            ip= eth.data
            src =socket.inet_ntoa(ip.src)
            tcp=ip.data
            http = dpkt.http.Request(tcp.data)
            if http.method =='GET':
                uri = http.uri.lower()
                print(uri)
                if '.zip' in uri and 'regbld' in uri:
                    print('[!]' + src + 'Downloaded LOIC.')
        except:
            pass
f = open('zip_test_tcpdump.pcap','rb')
pcap = dpkt.pcap.Reader(f)
findDownload(pcap)
