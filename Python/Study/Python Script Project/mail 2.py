import email.utils
import email.quoprimime
import getpass
import smtplib
from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email.MIMEText import MIMEText
from email import Encoders
import os


to ='rajkamal2013@outlook.com'
gmail_user='rajkamal2013@gmail.com'
gmail_pwd = ''
smtpserver = smtplib.SMTP('smtp.gmail.com','587')
smtpserver.ehlo()
smtpserver.starttls()
smtpserver.ehlo
smtpserver.login(gmail_user, gmail_pwd)
header = 'To:' + to + '\n' + 'From: ' + gmail_user + '\n' + 'Subject:testing \n'
print (header)
msg = header + '\n this is test msg from rajkamal \n\n'
smtpserver.sendmail(gmail_user, to, msg)
print ('done!')
smtpserver.close()
