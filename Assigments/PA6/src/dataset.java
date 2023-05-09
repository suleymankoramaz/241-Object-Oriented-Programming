import java.util.ArrayList;


//DATASET CLASS THAT HOLDS DATA (AUDIO-VIDEO-TEXT-IMAGE) 

//It's observable subject for observes.
//Observers can receive the list of this class and when
//list changed Observers to be informed and update themself
public class dataset
{
	//----------------------CLASS MEMBERS-------------------------//
	private ArrayList<data> playable_array = new ArrayList<data>();
	private ArrayList<data> non_playable_array = new ArrayList<data>();
	private ArrayList<Observer> observers = new ArrayList<Observer>();

	//Constructor
	public dataset(){}
	

	//------------------------FUNCTIONS---------------------------//

	//Function register observer to dataset
	public void register(Observer observer)
	{
		//Observe observer to this dataset(subject)
    	observer.set_subject(this);	
    	//Send ararylists of data
    	observer.set_list(playable_array,non_playable_array);	
    }

    //Function add observer to ArrayList of observers
    public void add_observer(Observer observer)
    {
    	//Add to list
    	observers.add(observer);
    }

    //Function remove observer from ArrayList of observers
    public void remove_observer(Observer observer)
    {
    	//Remove from list
    	observers.remove(observer);
    	//Observer quit from dataset and clear current playlist
    	observer.quit();
    }

    //Function add data to dataset ArrayLists
	public void add(data d)
	{
		//PLAYABLE ARRAYLIST
		if(d instanceof playable)
			playable_array.add(d);

		//NON-PLAYABLE ARRAYLIST		
		else
			non_playable_array.add(d);	

		//NOTIFY ALL OBSERVERS FOR UPDATE THEM
		notifyAllObservers();
	}

	//Function remove data from dataset ArrayLists
	public void remove(data del)
	{
		//CHECK PLAYABLE ARRAYLIST
		//AND IF DATA IS IN THERE 
		//REMOVE IT FROM THERE
		for(int i=0;i<playable_array.size();i++){
			if(playable_array.get(i) == del){
				playable_array.remove(i);
			}
		}

		//CHECK NON-PLAYABLE ARRAYLIST
		//AND IF DATA IS IN THERE 
		//REMOVE IT FROM THERE
		for(int i=0;i<non_playable_array.size();i++){
			if(non_playable_array.get(i) == del){
				non_playable_array.remove(i);
			}
		}

		//CONTROL OBSERVERS CURRENT_PLAYING DATA REMOVED		
		for (Observer observer : observers) {
   			observer.control_if_current_removed(del);
    	}

    	//NOTIFY ALL OBSERVERS FOR UPDATE THEM
		notifyAllObservers();
	}

	//Function notify all observer when list changed
    public void notifyAllObservers()
    {
    	//Loop for all observers
   		for (Observer observer : observers) {

   			//Call list setter of observer
   			observer.set_list(playable_array,non_playable_array);
    	}
    } 
}