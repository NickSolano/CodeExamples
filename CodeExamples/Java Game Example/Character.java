package Lab3.Lab4;

import java.util.Random;

/**
 * Created by Blackcitadelz on 2/14/2016.
 */
public class Character {

    private String name;
    private Random rngattack = new Random();
    private Move punch = new Move("Punch", 2);
    private Move kick = new Move("Kick", 3);
    private Move ninjutsu = new Move("Ninjutsu", 5);

    private Move[] theMoves = new Move[]{punch, kick, ninjutsu };
    private int healthPoints = 50;

    final int MAX = 5;

    public Character(String heroName){

        this.name = heroName;

    }

    public int getDamage() {
        return rngattack.nextInt(MAX);
    }

    public void printMoveNames(){

        for(int i = 0; i< theMoves.length; i++ ){
            System.out.println(i + " - " + theMoves[i].getName() );
        }
    }

    public void takeDamage(int damage) {
        healthPoints = healthPoints - damage;
    }
;

    public void attack(Character target, int moveId) {

        Move selectedMove = theMoves[moveId];

        //Calculate Damage
        int damage = getDamage() * selectedMove.getMultiplier();
        //Subtract health of the target
        target.takeDamage(damage);

        //Print out health of the target and damage amount ( status report )
        System.out.println(target.getName() + " has taken " + damage + " damage from " + selectedMove.getName());
        if ( target.getHealthPoints() <= 0){
            System.out.println(target.getName() + " has dead" + "!!" );
        } else {
            System.out.println(target.getName() + " has " + target.getHealthPoints() + "!");
        }


    }


    public String getName() {
        return name;

    }

    public int getHealthPoints() {
        return healthPoints;
    }
}
