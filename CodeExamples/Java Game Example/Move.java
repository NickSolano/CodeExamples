package Lab3.Lab4;

/**
 * Created by Blackcitadelz on 2/14/2016.
 */
public class Move {
    private String name;
    private int multiplier;

    public Move(String name, int damage){

        this.name = name;
        this.multiplier = damage;

    }

    public String getName(){
        return this.name;

    }

    public int getMultiplier(){
        return this.multiplier;

    }
}
