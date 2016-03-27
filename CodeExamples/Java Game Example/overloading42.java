package Lab3.Lab4;

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Blackcitadelz on 2/14/2016.
 */
public class overloading42 {
    public static void main(String[] args){

        Scanner userinput = new Scanner(System.in);
        Character orochimaru = new Character("Orochimaru");
        Character madara = new Character("Madara");
        Character naruto = new Character("Naruto");
        Character sasuke = new Character("Sasuke");

        Character[] availableCharacters = new Character[]{orochimaru, madara, naruto, sasuke};
        for (int i = 0; i < availableCharacters.length; i++) {
            //Print all the names with choice number
            System.out.println(  i + " - " + availableCharacters[i].getName());
        }

        //Select Character
        System.out.print(" Please Select your character!: ");
        int pickedCharacter = 69;
        boolean isValidInput = false;
        do {
            try {
                pickedCharacter = userinput.nextInt();
                isValidInput = true;
            } catch (InputMismatchException exception) {
                System.out.println("You dun goofed frig off, please enter your thing again");
                userinput.next();
            }


        } while (!isValidInput);

        Character myCharacter = availableCharacters[pickedCharacter];
        //Select random enemy character
        int randomInt = new Random().nextInt(3);
        Character enemyCharacter = availableCharacters[randomInt];

        //Display move and attack until ded3
        while(enemyCharacter.getHealthPoints() > 0){
            myCharacter.printMoveNames();
            System.out.println("Choose your attack: ");
            int move = userinput.nextInt();
            myCharacter.attack(enemyCharacter, move);

        }






    }
}
