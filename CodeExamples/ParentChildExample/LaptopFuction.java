/**
 * Created by Blackcitadelz on 3/14/2016.
 */
public class LaptopFuction {

    public static void main(String args[]) {

        MacBookAir macBookAir = new MacBookAir("Apple", 999.999, 10, "Intel Core i5 4500U", "Intel Integrated Graphics 5000", "256 GB SSD");
        MacBookPro macBookPro = new MacBookPro("Apple", 1399.99, 15, "Intel Core i7 5500U", "Intel Integrated Graphics 5500", "512 GB SSD");
        RazerBlade razerBlade = new RazerBlade("Razer", 2499.99, 17, "Intel Core i7 4720HQ", "960M Nividia Integrated Graphics", "512 GB SSD");
        Asus asus = new Asus("Asus", 799.99, 13, "Intel Core M", "Intel integrated graphics 5000", "256 GB SSD");

        System.out.println("--- LAPTOPS ---");
        System.out.println("--- Nicholas Solano ---");
        System.out.println("\n");
        System.out.println(" MAC LAPTOPS ");
        System.out.println("\n");
        System.out.println("--Mac Book Air--");
        System.out.println(macBookAir.toString());
        System.out.println("\n");
        System.out.println("\n");
        System.out.println("-- Mac Book Pro --");
        System.out.println(macBookPro.toString());
        System.out.println("\n");
        System.out.println("WINDOWS LAPTOPS");
        System.out.println("\n");
        System.out.println("--Asus Laptop --");
        System.out.println(asus.toString());
        System.out.println("\n");
        System.out.println("\n");
        System.out.println("-- The Ultimate Razer Blade --");
        System.out.println(razerBlade.toString());
        System.out.println("\n");

    }


}
