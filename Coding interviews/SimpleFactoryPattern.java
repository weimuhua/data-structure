public interface Car{
	public void run();
}

public class Benz implements Car{
	public void run(){
		System.out.println("Benz is running...");
	}
}

public class BMW implements Car{
	public void run(){
		System.out.println("BMW is running...");
	}
}

public class Factory{
	public static getCarInstance(String type){
		Car c = null;
		if(type.equals("Benz")){
			c = new Benz();
		}else if(type.equals("BMW")){
			c = new BMW();
		}
		return c;
	}
}

public static void main(String[] args){
	Car c =  Facorty.getCarInstance("BMW");
	c.run();
}
