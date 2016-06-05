'''
Created on Dec 17, 2014

@author: Iulian
'''

def print_students(s, i):
    if(i < len(s)):
        print(s[i])
        print_students(s, i+1)

