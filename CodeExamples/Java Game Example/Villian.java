package Lab3.Lab4;

import java.util.Random;

/**
 * Created by Blackcitadelz on 2/14/2016.
 */
public class Villian {

    private String name;
    private Random rngattack = new Random();
    private Move [] theMoves = new Move[]{new Move("Punch", 2), new Move("Kick", 3), new Move("Ninjutsu", 5)};
    private int healthPoints = 50;
    final int MAX = 20;


    public Villian(String Villianname){

        this.name = Villianname;

    }

    public int getDamage(){


        return rngattack.nextInt(MAX);
    }
    public void printMoveNames(){

        for(int i = 0; i< theMoves.length; i++ ){
            System.out.println(i + " - " + theMoves[i].getName() );
        }
    }



}



