/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*  unescape_json_string
 *  ====================
 *  Copyright (C) 2018 Flodila
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum { txt, escaped, unicode } unescape_json_string_state;

/*
 * Unescapes a JSON string value. See http://www.ietf.org/rfc/rfc4627.txt
 */
static int u8_unescape_json_string(char *buf, int buf_len, char **unesc_buf)
{
    int unesc_len = 0;
    char *p = *unesc_buf;

    char uxxxx[] = "xxxx"; // 4HEXDIG buffer for unicode sequences
    int uxxxxOffset; // current offset in uxxxx
    int long unicodePoint;
    unescape_json_string_state state = txt;

    for (int i = 0; i < buf_len; i++) {
        char ch = buf[i];
        if (state == txt) {
            if (ch == '\\') {
                state = escaped;
            } else {
                p[unesc_len++] = ch;
            }
        } else if (state == escaped) {
            if (ch == 'u') {
                state = unicode;
                uxxxxOffset = 0;
            } else {
                switch(ch) {
                    case 'n': p[unesc_len++] = '\n'; break; // line feed
                    case 't': p[unesc_len++] = '\t'; break; // tab
                    case 'r': p[unesc_len++] = '\r'; break; // carriage return
                    case 'b': p[unesc_len++] = '\b'; break; // backspace
                    case 'f': p[unesc_len++] = '\f'; break; // form feed
                    default: p[unesc_len++] = ch; break; // anything else
                }
                state = txt;
            }
        } else if (state == unicode) {
            uxxxx[uxxxxOffset++] = ch;
            if (uxxxxOffset == 4) {
                unicodePoint = strtol(uxxxx, NULL, 16);
                if (unicodePoint <= 0) {
                    // NOP
                } else if (unicodePoint < 0x80) {
                    p[unesc_len++] = (char) unicodePoint;
                } else if (unicodePoint < 0x800) {
                    p[unesc_len++] = (char) (0xC0 + unicodePoint / 0x40);
                    p[unesc_len++] = (char) (0x80 + unicodePoint % 0x40);
                } else {
                    p[unesc_len++] = (char) (0xE0 + unicodePoint / 0x1000);
                    p[unesc_len++] = (char) (0x80 + unicodePoint / 0x40 % 0x40);
                    p[unesc_len++] = (char) (0x80 + unicodePoint % 0x40);
                }
                state = txt;
            }
        } else {
            return -1; // panic: unknown state
        }
    }
    p[unesc_len] = '\0';
    return unesc_len;
}

int main(int argc, char *argv[])
{
    char *input;
    char *output;
    int input_len;
    int output_len;

    if (argc < 2) {
        printf("Argument expected.\n");
        return 1;
    }
    input = argv[1];

    printf("Input:\n------\n%s\n\n", input);

    input_len = strlen(input);

    // allocate memory for output
    output = (char *) calloc((input_len + 1), sizeof(char));

    // call unescape function
    output_len = u8_unescape_json_string(input, input_len, &output);

    printf("Output:\n-------\n%s\n\n", output);


    return 0;
}
