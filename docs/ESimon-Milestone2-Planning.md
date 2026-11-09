> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   
  Dimension 7
**What does your program currently do? (1–3 sentences)**   
→
is turn based video with a working prototype of and in-battle function that will run until player or CPU health reaches zero.  
---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   IN battle function, character constructor, enemy constructor.
  
**What is NOT working or incomplete?**   
→   menu system stop working to my liking after In battle function was place in menu logic .
  
**What feels confusing or messy in your code?**   
→

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   level system
→   
  
**What does this feature do?**   
→   will have a dedicated level progression for the four character types of the game.
  
**Why is this feature important?**   
→   will make each character feel unique and give player different way in which player would use each character.
  
---
### Feature 2  
**Name:**   Save Data
→   
  
**What does this feature do?**   
→   will save player game progress like party member, items, weapons, level, and inventory.
  
**Why is this feature important?**   
→   player wont have to start from level one if player  turn off program
  
---
  
### Feature 3 (optional)  
**Name:**   
→   
  
**What does this feature do?**   
→   
  
**Why is this feature important?**   
→   
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   will need to create a battle class  that will hold battle logic.
  
**Will you modify any existing classes? How?**   
→   will need to modify stats classes, may need to remove entirely and declare player stats (HP,MP,MPW,AP,D,SP) in character class.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   will use vectors for inventory and items system.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   prompts main menu , waits on user to select start, load save, and exit
2. User chooses → start    
3. Program responds → displays title and waits for user to press any key  
4. Loop/next step →   enter battle loop until player or CPU HP reaches 0
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→ 
  
- Better error handling:   
→   will prompt player that an invalid input was entered and to try again until user input is correct.
  
- Improved menu/navigation:   
→     have a key to show user how to navigate menu.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   the hardest part this week was trying to update player stats that where stored in stats class no matter what I did player stats like current HP or MP weren't updating.
  
**What is your plan if you get stuck?**   
→   
  my plan is to look for forums with a related problem like mines and reading and testing out every solution in the responses.
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   would like to improve understanding and usage of classes
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   practice classes when I'm able too and watch videos breaking down classes and there many implementation.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [x]   prototype of in Battle function
- [x]   enemy class
- [x]   Items class
- [ ]   
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.