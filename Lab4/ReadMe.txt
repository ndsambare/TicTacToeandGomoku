Name: Namit Sambare and William Loh  Project: Lab 4

Errors: 
Error 1 - 
One error that we kept running into was that every time I put my first piece down, the game would be declared a draw. The draw method checks first to see if (even if there is white space) there can be no piece that wins the game. Of course, the draw method also returns a draw if the board is full and the game is not won as well. 

Solution - Our concept for implementing draw was to fill two copies of the board with all white or all black pieces in the empty slots. If this copy of the board returned true for done() that means that player could still win. Our code was right initially, we just returned true when we should've returned true for that part.

Error 2 - 
Another error is that when the TicTacToe game is played, the user is allowed to put a piece in indices with 0 or 4. Also, the spacing of the game board does not match up with 
the piece coordinates. 

Solution - We added a protected member variable called "isGomoku" that indicates whether or not the game being played is Gomoku or not. If it isn't, then we have constraints in the prompt() method that will adjust accordingly. 


Trial 1: Input: "Lab 4.exe TicTacToe"
Output: The game worked just as it should have and ended with Player X getting three in a row. 

Trial 2: Input: "Lab 4.exe TicTacToe" so that no player would win
Output: The game worked and when all the spots in the board were filled and no player had won, the game printed that it was a draw. 

Trial 3: Input: "Lab 4.exe TicTactoe" so that player X would win
Output: The game worked and when player X had three in a row, the game printed out that player X had won. 

Trial 4: Input: "Lab 4.exe TicTacToe" so that player O would win
Output:  The game worked and when player O had three in a row, the game printed out that player O had won. 

Trial 5: Next, I tried inputting various arguments that should not make sense. For example, the program should only take in input of the type "2,3", where both numbers are numbers between 1 and 3 and there is no other punctuation. 

   Various Input I tried: 
   1. "3,3" - worked as expected and put a mark at 3,3
   2. "3, 3" - spaces are not allowd so there was no mark put and user was prompted again
   3. "3 3" - spaces are not allowed and the numbers must be separated by commas so the user was prompted again 
   4. "3,3,3" - only two numbers are allowed so the user was prompted again
   5. "1,1," -only three characters are allowed : two numbers and one comma, so the user was prompted again
   6. "     " - there must be numbers so the user was prompted again
   7. "0,0" - This coordinate is not in the correct board range, so the user was prompted again
   8. "a,s" - There are no numbers so the user was prompted again

Trial 6: Next, I played the game so that the X's would win in a horizontal fashion, and the program worked as expected and printed out that X won. 

Trial 7: I played the game so that the X's would win in a vertical fashionm, and the program worked as expected and printed out that X won. 

Trial 8: I played the game so that the X's would win in both diagonal fashions, and the program worked as expected and printed out that X won. 

Trial 9: I tested each case (one vertical, one horizontal, and two diagonals) of winning the game for Player O, and the program worked as expected and printed out that O won. 

Trial 10: My input for the first terminal input was "Lab4.exe      " 
I recieved the correct expected output of the usage message prompting me with the correct output of "Lab4.exe TicTacToe"

Trial 11: My input for the first terminal input was "         "
I recieved the correct expected output of the usage message prompting me with the correct output of "Lab4.exe TicTacToe"

Trial 12:  My input for the first terminal input was "Lab 4"       

I recieved the correct expected output of the usage message prompting me with the correct output of "Lab4.exe TicTacToe"

Trial 13: I played the game so that no moves would remain and it would be a draw, and I got the expected output and the program printed that it was a draw. 

Trial 14: I played the game and halfway through I typed "quit" and the program did as expected and quit the game. 

Trial 15: I played the game and halfway through I typed "qui" and the program did as expected and prompted the user again. 

--------- Now the trial runs for Gomoku ----------

Trial 16: Input: "Lab 4.exe Gomoku" -- I played the game until all the spots on the board were full and no player had won. 

The game output that the result was a draw as it should have. 

Trial 17: "Lab 4.exe Gomoku" -- I played the game until there were 5 in a row horizontally for player B
The game output correctly showed that player B had won. 

Trial 18: "Lab4.exe Gomoku" -- I played the game until there were 5 in a row vertically for player B
The game output correctly showed that player B had won. 

Trial 19: "Lab4.exe Gomoku" -- I played the game until there were 5 in a row on the right to left diagonal for player B
The game output correctly showed that player B had won. 

Trial 20: "Lab4.exe Gomoku" -- I played the game until there were 5 in a row on the left to right diagonal for player B
The game output correctly showed that player B had won. 

Trial 17: "Lab 4.exe Gomoku" -- I played the game until there were 5 in a row horizontally for player W
The game output correctly showed that player W had won. 

Trial 18: "Lab4.exe Gomoku" -- I played the game until there were 5 in a row vertically for player W
The game output correctly showed that player W had won. 

Trial 19: "Lab4.exe Gomoku" -- I played the game until there were 5 in a row on the right to left diagonal for player W
The game output correctly showed that player W had won. 

Trial 20: "Lab4.exe Gomoku" -- I played the game until there were 5 in a row on the left to right diagonal for player W
The game output correctly showed that player W had won. 
