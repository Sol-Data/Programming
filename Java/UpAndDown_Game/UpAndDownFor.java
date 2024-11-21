/*
 * Guess the number of cards (up&down game)

 * Create a game to guess the number of hidden cards. This is a game where a card with a random number from 0 to 99 is hidden and the player has to guess the number of cards. 
   For example, if the number in the card is 77, as shown in the screen below. If the person guessing the number enters 55, they can click “Higher”. If they guess 70, you guess “higher,” and so on, narrowing the range. To repeat the game, you'll be asked y/n, and if it's n, it's over.

 * Hint
   To randomly select the number of hides the computer can make, we use the Random class.

 * import java.util.Random;
 * Random r = new Random(); 
 * int k = r.nextInt(100); // Generate a random integer from 0 to 99
 * The only other way to generate a random number is to use the Math.random() method of class Random. 

 * In response to “Do you want to do it again (y/n) >>”, the user enters either “y” or “n”, and the received string is compared using the following code

 * String text = scanner.next(); //Enter a “y” or “n” string from a user
 * if(text.equals("n")) {
	// Write to exit
   }
 */

 import java.util.Random;
 import java.util.Scanner;
 
 public class UpAndDownFor{
     public static void main(String args[]) {
         Random r = new Random();
         Scanner scanner = new Scanner(System.in);
 
         while(true) {
             int pc = r.nextInt(100); //Generate random numbers between 0-99
             System.out.println("I've decided the number. Guess");
 
             int count = 1, max = 99, min = 0;
             String option = "";
 
             while(true) {
                 System.out.println(min+"-"+max);
                 System.out.print(count+">>");
                 int user = scanner.nextInt();
 
                 if(user>pc){
                     System.out.println("Lower");
                     max = user;
                 }
                 else if(user<pc) {
                     System.out.println("Higher");
                     min = user;
                 }
                 else {
                     System.out.println("Correct.");
                     break;
                 }
                 count++;
             }
             System.out.print("Do you want to do it again?(y/n)>>");
             option = scanner.next();
 
             if(option.equals("y")) continue;
             else break;
         }
 
         System.out.print("Exit the program.");
         scanner.close();
         return;
     }
 }
 
 
 
 
 