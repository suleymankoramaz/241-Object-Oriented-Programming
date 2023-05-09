//  SUBCLASS IMAGE  //

public class image extends data implements visual , non_playable 
{
	//CONSTRUCTORS

	//parameters: name
	public image(String n){super(n);}
	//parameters: name - dimension - other info /-\ CALL SUPERCLASS CONSTRUCTOR
	public image(String n,double dim,String other){super(n,dim,other);}

	//non_playable_info() function from interface
	public void non_playable_info(){
		System.out.println("INFORMATION OF PAINTING");
		System.out.printf("Name of the painting: %s-",get_name());
		System.out.printf("Dimention = %.2f-",get_dd());
		System.out.println("It's non-playable.-");
		System.out.printf("Other information about data: %s\n\n",get_other());
	}
	public void visual_info(){System.out.printf("Dimention = %.2f-",get_dd());}
}