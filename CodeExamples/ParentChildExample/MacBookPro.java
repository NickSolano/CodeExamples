/**
 * Created by Blackcitadelz on 3/14/2016.
 */
public class MacBookPro extends macLaptop {
    protected String cpu;
    protected String gpu;
    protected String hardDrive;

    public MacBookPro( String manufacturer, double price, double weight, String cpu, String gpu, String hardDrive)
    {
        super(manufacturer,price,weight);
        this.cpu = cpu;
        this.gpu = gpu;
        this. hardDrive = hardDrive;

    }
    public String getCpu(){
        return this.cpu;
    }

    public String getGpu() {
        return this.gpu;
    }

    public String getHardDrive() {
        return this.hardDrive;
    }
    public String toString(){

        String result = super.toString();

        result += "\nCPU Type: " + getCpu() + "\n";
        result += "GPU Type: " + getHardDrive() + "\n";
        result += "Hard Drive Type: " + getHardDrive();

        return result;
    }
}
