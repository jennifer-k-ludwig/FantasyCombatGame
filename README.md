# Fantasy Combat Game
This fantasy combat game allows two players to choose their characters and battle it out with the roll of a die. Each character has their own die (or dice) of varying sides, and their own special "moves". Each round consists of two attacks, where each character alternates between the attacker and defender. A player loses when all strength points are lost.

## Usage
Each player chooses a character.
![photo1](/screenshots/photo1.GIF)

During each round, the attacks are in randomized order. If a player rolls a specific number, a character may use their special attack. The  total damage from the attack is attacker's roll - defender's roll - defender's armor. The total damage is subtracted from the defender's strength points.
![photo2](/screenshots/photo2.GIF)
![photo3](/screenshots/photo3.GIF)

When one of the players is out of strength points, the game is over. At this point, there is the option to play again or quit.
![photo4](/screenshots/photo4.GIF)

## Deployment
To deploy and play, please use the makefile.

## Built With
* C++

## Contributing
This project is closed to contributions at this time.

## Authors
Jennifer K. Ludwig
