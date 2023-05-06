## How i know
- I learn this from google search and youtube tutorial.
- But i only learn alittle, but im not gonna learn more, its to difficult.
## Breakdown
```bf
++++++++                    ; Initialize the first cell to 8 (ASCII value of '[')
[>++++                      ; Move to cell 2 and set its value to 4
    [>++                    ; Move to cell 3 and set its value to 2
        >+++                ; Move to cell 4 and set its value to 3
        >+++                ; Move to cell 5 and set its value to 3
        >+                  ; Move to cell 6 and set its value to 1
        ><<<<-              ; Move back to cell 2 and decrement its value by 4
    ]
    >+                      ; Move to cell 3 and increment its value by 1
    >+                      ; Move to cell 4 and increment its value by 1
    >-                      ; Move to cell 5 and decrement its value by 1
    >                      ; Move to cell 6
    +[<]<-                  ; Move back to cell 2 and copy its value to cells 1 and 3
]
>>.                         ; Move to cell 3 and print its value (ASCII value of '2')
>---.                       ; Move to cell 6 and print its value (ASCII value of '5')
+++++++..                   ; Move to cell 7 and print its value twice (ASCII value of '7')
+++.                        ; Move to cell 8 and print its value three times (ASCII value of '\t')
>>.<-.                      ; Move to cell 10, print its value (ASCII value of '\n'), move to cell 9, and decrement its value by 1
<.+++.                      ; Move back to cell 8, increment its value by 3, and print its value (ASCII value of ':')
------.                     ; Move to cell 7, decrement its value by 6, and print its value (ASCII value of '\x03')
--------.                   ; Move to cell 6, decrement its value by 8, and print its value (ASCII value of '\x08')
>>+.                        ; Move to cell 8, increment its value by 1, and print its value (ASCII value of ';')
>++.                        ; Move to cell 10, increment its value by 2, and print its value (ASCII value of '\r')
```
