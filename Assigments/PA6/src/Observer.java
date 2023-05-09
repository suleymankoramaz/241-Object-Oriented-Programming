import java.util.ArrayList;


//  ABSTRACT CLASS OF OBSERVERS PLAYER AND VIEWER  //
public abstract class Observer {

    //------------CLASS MEMBERS----------------//

    //play_list  
    protected ArrayList<data> play_list;

    //observed subject
    protected dataset subject;

    //current_playing from play_list
    protected data current_data;

    //---------------FUNCTIONS-----------------//

    //Function observes observer to subject
    public abstract void set_subject(dataset subject);

    //Funtion update play_list
    public abstract void set_list(ArrayList<data> p,ArrayList<data> np);

    //Function that clean playlist and quit from subject when observer removed from subject 
    public abstract void quit();

    //Function show all data in the play_list
    public abstract void show_list();
    
    //Function return currently_playing data in the playlist 
    public abstract data currently_playing();

    //Function go next data in play_list
    public abstract void next(String type);

    //Function go previous data in play_list
    public abstract void previous(String type);

    //Function control current_playing data removed
    //If it removed go next data of same type 
    public abstract void control_if_current_removed(data del);

}