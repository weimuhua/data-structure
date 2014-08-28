public class Singleton{
	private static class SingletonHolder{
		private static final Singleton instance = new Singleton();
	}
	public static final Singlton getInstance(){
		return SingletonHolder.instance;
	}
}
