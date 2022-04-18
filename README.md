> :information_source: This project is currently work in progress

# rex
[![](https://tokei.rs/b1/github/ChronesDev/Rex?category=files)](https://github.com/ChronesDev/Rex)
[![](https://tokei.rs/b1/github/ChronesDev/Rex?category=code)](https://github.com/ChronesDev/Rex)

**What is Rex?** \
Rex is another retained UI engine built on top of YogaLayout. 
Rex basically does everything except rendering and directly handling events (like key presses or ect.).
What Rex mainly does is managing the layout, like alignment, sizes, padding or ect. and structuring the element relations.

**What about Index UI?** \
Rex is built on top of Index and should fix all the flaws Index UI had. 
So basically Index UI is deprecated and Rex is here to replace it.

**When to use Rex?** \
When you have the option to work in another language (like C#) then you should probably choose other UI libraries. 
If you have a bad time calculating layout for a immediate library, 
then Rex should be a good choice as it has a very powerful layout engine that behaves similarly to CSS' Flexbox and WPF's layout system.


**How to use Rex?** \
In order to use Rex, __you need to have your own rendered__.
As stated before, Rex does not handle rendering or events for you, that's why you also need to implement input events.
As of best practises there will soon be a guide on how to implement Rex for your needs.
