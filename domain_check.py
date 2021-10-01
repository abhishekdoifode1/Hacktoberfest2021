#!/usr/bin/python3

import whois
from dotenv import load_dotenv
from datetime import datetime
from sys import argv, exit
import json
import requests
import os

load_dotenv()

webhook_url = os.environ.get('WEB_HOOK_URL')
threshold = int(os.environ.get('THRESHOLD'))


def sendMessage(msg):
    slack_data = {'text': msg}

    response = requests.post(webhook_url, data=json.dumps(
        slack_data), headers={'Content-Type': 'application/json'})
    if response.status_code != 200:
        raise ValueError('Request to slack returned an error %s, the response is:\n%s' % (
            response.status_code, response.text))


now = datetime.now()

if len(argv) < 2:
    print('No domain file specified on the command line, usage:  ')
    print('')
    print('    ./check-domain.py domain-file or python3 check-domain.py domain-file')
    exit(1)

domainName = argv[1]

file = open(f"{domainName}", "r")
f = file.read().split("\n")

for domain in f:
    try:
        flags = 0
        flags = flags | whois.NICClient.WHOIS_QUICK
        w = whois.whois(domain, flags)

    except whois.parser.PywhoisError as e:
        msg = f'`{domain}` has {e}'
        sendMessage(msg)
        print(e)
        

    if type(w.expiration_date) == list:
        w.expiration_date = w.expiration_date[0]
    else:
        w.expiration_date = w.expiration_date

    try:
        domain_expiration_date = str(w.expiration_date.day) + '/' + \
            str(w.expiration_date.month) + '/' + str(w.expiration_date.year)


        timedelta = w.expiration_date - now
        days_to_expire = timedelta.days
        provider = w.registrar

        if timedelta.days <= threshold:

            msg = f'`{domain}` is expiring on `{domain_expiration_date}`, `{days_to_expire}` days to go. | Provider `{provider}` |'
            sendMessage(msg)
            print("\nMessage sent")
        
            
    except AttributeError as e:
        msg = f'`{(domain.split())[0]}` is either expired or is not valid.'
        sendMessage(msg)
        print(f'{e} and {w}')
        
file.close()

    
