import java.util.ArrayList;


//  DERIVER OBSERVER CLASS  // 
public class Player extends Observer
{
    //Constructor
    public Player(){play_list = new ArrayList<data>();}

    
    //FUNCTION PROPERTIES ARE SPECIFIED IN ABSTRACT CLASS OBSERVER//
    public void set_subject(dataset subject)
    {   
        //assign observed subject
        this.subject = subject;
        //add observer to observers arraylist in dataset
        this.subject.add_observer(this);
    }

    //p PARAMETER FOR PLAYABLE LIST - np PARAMETER FOR NON-PLAYABLE LIST//
    //THIS FUNCTION JUST USING P BECAUSE THIS CLASS IS PLAYER , SO IT'S USING JUST PLAYABLE OBJECTS
    public void set_list(ArrayList<data> p,ArrayList<data> np)
    {
        //control data for assign current_data 
        int control=0;
        //clear play_list to uptade
        this.play_list.clear();

        //fill play_list with new arraylist from dataset
        for(int i=0;i<p.size();i++){
            this.play_list.add(p.get(i));
            if(current_data == p.get(i))
                control++;
        }
        //if there is no current_data assign first data in play_list to current_data
        if(control==0)
           current_data = this.play_list.get(0);
    }
    public void quit()
    {
        //quit observed subject
        this.subject = null;
        //clear current play_list
        play_list.clear();
    }
    public  void show_list()
    {
        //Player can't receive list.
        if(this.subject == null)
            System.out.println("Player can't receive list.");
        //List is empty
        else if(play_list.size()==0)
            System.out.println("List is empty.");
        //Otherwise print play_list
        else{
            System.out.println("Playlist of this player:");
            for(int i=0;i<this.play_list.size();i++)
                System.out.printf("%d: %s\n",i+1,this.play_list.get(i).get_name());
            System.out.printf("\n");
        }
    }
    public data currently_playing()
    {
        return current_data;
    }
    public  void next(String type)
    {
        //This data nessesery because if there is no
        //next data in same type current_data should
        //be first data or play_list 
        int new_index=-1;

        for(int i=0;i<play_list.size();i++){

            //Find current_data in playlist
            if(current_data.get_name() == play_list.get(i).get_name())

                //Find data has same type with current_data next to current_data
                //if there is no data has same type with current_data new_index don't change 
                for(int j=i+1;j<play_list.size();j++){

                    if(play_list.get(j) instanceof visual && type == "video"){
                        new_index = j;
                        break;
                    }
                    //If current_data is not playable find next playable data
                    else if(play_list.get(j) instanceof non_visual && type == "audio"){
                        new_index = j;
                        break;
                    }
                }           
            }

        //Assign current_data
        //If there is no next data of that type go first data of that type
        if(new_index == -1){
            for(int i=0;i<play_list.size();i++){
                if(play_list.get(i) instanceof visual && type == "video"){
                    current_data = play_list.get(i);
                    break;
                }
                else if(play_list.get(i) instanceof non_visual && type == "audio"){
                    current_data = play_list.get(i);
                    break;
                }
            }        }
            
        else
            current_data = play_list.get(new_index);
    }
    public  void previous(String type)
    {
        //This data nessesery because if there is no
        //next data in same type current_data should
        //be first data or play_list 
        int new_index=-1;

        for(int i=0;i<play_list.size();i++){

            //Find current_data in playlist
            if(current_data.get_name() == play_list.get(i).get_name())

                //Find data has same type with current_data previous to current_data
                //if there is no data has same type with current_data new_index don't change 
                for(int j=i-1;j>=0;j++){

                    //If current_data is playable find next playable data
                    if(play_list.get(j) instanceof visual && type == "video"){
                        new_index = j;
                        break;
                    }
                    //If current_data is not playable find next playable data
                    else if(play_list.get(j) instanceof non_visual && type == "audio"){
                        new_index = j;
                        break;
                    }
                }           
            }

        //Assign current_data
        //If there is no previous data of that type go first data of that type
        if(new_index == -1){
            for(int i=0;i<play_list.size();i++){
                if(play_list.get(i) instanceof visual && type == "video"){
                    current_data = play_list.get(i);
                    break;
                }
                else if(play_list.get(i) instanceof non_visual && type == "audio"){
                    current_data = play_list.get(i);
                    break;
                }
            }
        }
            
        else
            current_data = play_list.get(new_index);
    }
    public void control_if_current_removed(data del)
    {
        if(current_data == del){
            if(del instanceof visual)
                this.next("video");
            else if(del instanceof non_visual)
                this.next("audio");
        }
    }
}