# How to encode and decode Python's strings into a type called bytes
# How to handle errors in your strings and byte handling

import sys
script, encoding, error = sys.argv


def main(language_file, encoding, errors):
    line = language_file.readline()  
 
    if line:
        print_line(line, encoding, errors)
        return main(language_file, encoding, errors)

''' The readline function will return an empty string when it reaches the end of the file and if line simply tests for this empty string. 
 As long as readline gives us something, this will be true, and the code under (indented in, lines 9–10) will run. When this is false, 
 Python will skip lines 9–10 '''


def print_line(line, encoding, errors):
    next_lang = line.strip()
    raw_bytes = next_lang.encode(encoding, errors=errors)
    cooked_string = raw_bytes.decode(encoding, errors=errors)

    print(raw_bytes, '<===>', cooked_string)


languages = open('languages.txt', encoding='utf-8')

main(languages, encoding, error)

# OUTPUT
""" The 17.py script is taking bytes written inside the b'' (byte string) and converting them to the UTF-8 or other encoding you specified .
On the left is the numbers for each byte of the UTF-8 (shown in hexadecimal), and the right has the character output as actual UTF-8.
The way to think of this is the left side of <===> is the Python numerical bytes, or the “raw” bytes Python uses to store the string.
You specify this with b'' to tell Python this is bytes. These raw bytes are then displayed “cooked” on the right so you can see the real
characters in your Terminal 

raw_bytes = b'' #starts with b''
All you need to remember is if you have raw bytes, then you must use .decode() to get the string. Raw bytes have no convention to them.
They are just sequences of bytes with no meaning other than numbers, so you must tell Python to “decode this into a UTF string.” If you have a
string and want to send it, store it, share it, or do some other operation, then usually it’ll work, but sometimes Python will throw up an error
saying it doesn’t know how to “encode” it. Again, Python knows its internal convention, but it has no idea what convention you need.
In that case, you must use .encode() to get the bytes you need

The way to remember this is DBES ( Decode bytes, encode strings)
"""
