# Siete y Medio 
Single-player card game where user plays against the computer. Goal of the game is to get cards whose total value comes closest to 7.5 without busting. Program keeps a .txt log of rounds played. 

# Attribution 
- Files: cards.cpp; cards.h; siete_y_medio.cpp
- Purpose: Simulate Mexican card game called Siete y Medio. Contains declarations and implementations of classes Card, Hand, and Player. Main function to execute the game. 
- Assembler: Kathyhan Nguyen 

# Test Case 
```
You have $100. Enter bet: 50
Your cards:
        Sota de copas           (Jack of cups).
Your total is 0.5.

Do you want another card (y/n)?
y

New card:
        Cinco de copas          (Five of cups).
Your cards:
        Sota de copas           (Jack of cups).
        Cinco de copas          (Five of cups).
Your total is 5.5. Do you want another card (y/n)?
y

New card:
        Caballo de espadas              (Knight of spades).
Your cards:
        Sota de copas           (Jack of cups).
        Cinco de copas          (Five of cups).
        Caballo de espadas              (Knight of spades).
Your total is 6. Do you want another card (y/n)?
n

Dealer's cards:
        As de espadas           (Ace of spades).
The dealer's total is 1.

New card:
        Cinco de espadas                (Five of spades).

Dealer's cards:
        As de espadas           (Ace of spades).
        Cinco de espadas                (Five of spades).
The dealer's total is 6.

Nobody wins!
You have $100. Enter bet: 100
Your cards:
        Seis de copas           (Six of cups).
Your total is 6.

Do you want another card (y/n)?
y

New card:
        Dos de copas            (Two of cups).
Your cards:
        Seis de copas           (Six of cups).
        Dos de copas            (Two of cups).
Your total is 8.
Dealer's cards:
        Sota de copas           (Jack of cups).
The dealer's total is 0.5.

New card:
        Tres de bastos          (Three of clubs).

Dealer's cards:
        Sota de copas           (Jack of cups).
        Tres de bastos          (Three of clubs).
The dealer's total is 3.5.

New card:
        Siete de bastos         (Seven of clubs).

Dealer's cards:
        Sota de copas           (Jack of cups).
        Tres de bastos          (Three of clubs).
        Siete de bastos         (Seven of clubs).
The dealer's total is 10.5.

You lose $100!

You have $0. GAME OVER!
Come back when you have more money.
```
