# A-mini-math-game  
  
This is the first C++ game that I make (maybe), finished in a few hours.  
Finish Date: 07/27/2021 (first version)  
  
# Introduction  
  
This is a math game to test your math ability and your reaction speed! (or how fast you type your answers)  
  
In this game, questions will appear after the end of the countdown, one question per time.  
You need to answer as many questions as possible. If your answer is correct, 10 points will be added to your score, otherwise, your score will be deducted 10 points.  
Although the scoring method I mentioned is easy to understand, I will someday update the scoring method and add the exported txt file to facilitate recording your best results.  
  
# Difficulties
  
* To create the countdown system  
It took me sometime to make the effect that I want.  
  
```C++
cout << "\r";
```
  
By using "\r", I can print the text I want from the first space of the same line to make the effect.  
This is my first time using "\r" in my code, it feels preety cool.

* To change the color of the text
I used the code below in the first place, but I realized something wrong.

```C++
#include <windows>

int main()
{
  system("Color 0A");
}
```
This will change the color of all texts in the terminal. This is something I don't like to see.  
So, I search the net to find if there's a way. This is what I found.  
```C++
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|0x0007);
```
This will change the text under this line of code, which can make the effect I want come true, feels good.  
  
# Conclusion  
  
Like I mentioned in the front of this markdown file, this is my first time making a mini game.  
I still have many shortcomings. However, you are welcome to download the exe file and play with it!  
Looking forward for your feedback!

I am not really good at English writing, please correct anytime!
Thanks for your watching, have fun :D

Michael Hsueh 07/28/2021
