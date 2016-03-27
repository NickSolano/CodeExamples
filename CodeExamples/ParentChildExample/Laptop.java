/**
 * Created by Blackcitadelz on 3/14/2016.
 */


abstract public class Laptop {

    protected String manufacturer;
    protected double price;
    protected double weight;

    public Laptop(String manufacturer, double price, double weight){

        this.manufacturer = manufacturer;
        this.price = price;
        this.weight = weight;

    }
    public String toString(){

        String result = "Manufacturer: " + this.manufacturer + "\n";
        result += "Price: $" + this.price + "\n";
        result += "Weight: " + this.weight + " pounds";
        return result;
    }





}
