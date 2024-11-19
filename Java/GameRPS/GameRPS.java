import java.util.Scanner;

public class GameRPS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str[] = {"rock", "paper", "scissors"};

        System.out.println("Play rock-paper-scissors with computer!");
        System.out.print("rock-paper-scissors!>>");
        String option = sc.next();

        while (!option.equals("stop")) {
            int n = (int)(Math.random()*3);
            System.out.print("user = "+option+", computer = "+str[n]+", ");
            if(n==0) {
                switch (option) {
                    case "rock":
                        System.out.println("Draw");
                        break;
                    case "paper":
                        System.out.println("User wins");
                        break;
                    case "scissors":
                        System.out.println("Computer wins");
                        break;
                    default:
                        break;
                }
            } else if(n==1) {
                switch (option) {
                    case "rock":
                        System.out.println("Computer wins");
                        break;
                    case "paper":
                        System.out.println("Draw");
                        break;
                    case "scissors":
                        System.out.println("User wins");
                        break;
                    default:
                        break;
                }
            } else {
                switch (option) {
                    case "rock":
                        System.out.println("User wins");
                        break;
                    case "paper":
                        System.out.println("Computer wins");
                        break;
                    case "scissors":
                        System.out.println("Draw");
                        break;
                    default:
                        break;
                }
            }

            System.out.print("rock-paper-scissors!>>");
            option=sc.next();

            if(option.equals("stop"))
                System.out.println("Game over");
        }
        sc.close();
    }
}
