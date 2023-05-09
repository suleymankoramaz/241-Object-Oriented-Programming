import java.util.ArrayList;


public class Main{

	public static void main(String[] args) {
		
		dataset ds = new dataset();

		Player p1 = new Player();
		Player p2 = new Player();
		Viewer v1 = new Viewer();
		Viewer v2 = new Viewer();

		ds.add(new image("Girl with a Pearl Earring", 1200.50, "Artist: Johannes Vermeer"));
		ds.add(new image("Guernica", 1250.30, "Artist: Pablo Picasso"));
		ds.add(new image("The Starry Night", 980.65, "Artist: Vincent Van Gogh"));
		ds.add(new image("The Kiss", 1100.32, "Artist: Gustav Klimt"));
		ds.add(new image("The Scream", 870.24, "Artist: Edvard Munch"));
		ds.add(new audio("Fularsız Entellik", 21.16, "Info: Tolstoyevsky's podcast series."));
		ds.add(new audio("Nereden Başlasam?", 39.13, "Info: Mirgun Cabas and Can Kozanoglu's podcast series."));
		ds.add(new audio("Socrates Podcasts", 68.10, "Info: Sokrates Dergi's podcast series."));
		ds.add(new video("The Shining (1980)", 146.10,2000, "Director:  Stanley Kubrick"));
		ds.add(new video("Green Mile (1999)", 189.50,2000, "Director: Frank Darabont"));
		ds.add(new video("Interstellar (2014)", 168.40,2000, "Director: Christopher Nolan"));
		ds.add(new text("Crime and Punishment", "Authot: Fyodor Dostoyevski"));
		ds.add(new text("Les Miserables", "Author: Victor Hugo"));
		ds.add(new text("The Lily of the Valley", "Author: Honore de Balzac"));

		ds.register(p1);
		ds.register(p2);
		ds.register(v1);
		ds.register(v2);

		System.out.println("Player1");
		p1.show_list();
		System.out.println("\nPlayer2");
		p2.show_list();
		System.out.println("Viewer1");
		v1.show_list();
		System.out.println("\nViewer2");
		v2.show_list();

		playable play1 = (playable)p1.currently_playing();
		playable play2 = (playable)p2.currently_playing();
		non_playable n_play1 = (non_playable)v1.currently_playing();
		non_playable n_play2 = (non_playable)v2.currently_playing();

		System.out.println("---------------------------------------------");
		System.out.println("INFORMATION CURRENT_PLAY OF PLAYER1 AND PLAYER2");
		System.out.println("---------------------------------------------");
		play1.playable_info();
		play2.playable_info();
		System.out.println("---------------------------------------------");
		System.out.println("INFORMATION CURRENT_PLAY OF VIEWER1 AND VIEWER2");
		System.out.println("---------------------------------------------");
		n_play1.non_playable_info();
		n_play2.non_playable_info();
		

		//PLAYER1 GO NEXT AUDIO - PLAYER2 GO NEXT VIDEO - VIEWER1 GO NEXT TEXT 2 TIMES - VIEWER2 GO NEXT IMAGE//
		p1.next("audio");
		p2.next("video");
		p2.next("video");
		p2.next("video");
		v1.next("text");
		v1.next("text");
		v2.next("image");


	    play1 = (playable)p1.currently_playing();
	    play2 = (playable)p2.currently_playing();
		n_play1 = (non_playable)v1.currently_playing();
		n_play2 = (non_playable)v2.currently_playing();

		System.out.println("-------------------------------------------------------------");
		System.out.println("INFORMATION CURRENT_PLAY OF PLAYER1 AND PLAYER2 AFTER GO NEXT");
		System.out.println("-------------------------------------------------------------");
		play1.playable_info();
		play2.playable_info();
		System.out.println("-------------------------------------------------------------");
		System.out.println("INFORMATION CURRENT_PLAY OF VIEWER1 AND VIEWER2 AFTER GO NEXT");
		System.out.println("-------------------------------------------------------------");
		n_play1.non_playable_info();
		n_play2.non_playable_info();

		System.out.println("-------------------------------------------------------------");
		System.out.println("INFORMATION CURRENT_PLAY OF PLAYER1 AFTER GO BACK 2 TIMES");
		System.out.println("-------------------------------------------------------------");


		//PLAYER1 GO PREVIOUS AUDIO 2 TIMES BUT THERE IS NO 2 AUDIO BEFORE CURRENT SO
		//IT GOES FIRST AUDIO DATA AND KEEPS GO IN THERE 
		p1.previous("audio");
		p1.previous("audio");
		play1 = (playable)p1.currently_playing();
		play1.playable_info();

		System.out.println("-------------------------------------------------------------");
		System.out.println("INFORMATION CURRENT_PLAY OF VIEWER1 AFTER REMOVE CURRENT_DATA");
		System.out.println("-------------------------------------------------------------");

		//WHEN CURRENT DATA REMOVED OF PLAYER1, IT PLAYS FIRST DATA OF LIST
		ds.remove((data)n_play1);
		n_play1 = (non_playable)v1.currently_playing();
		n_play1.non_playable_info();

		System.out.println("-------------------------------------------------------------");
		System.out.println("INFORMATION CURRENT_PLAY OF VIEWER1 AFTER GO NEXT 3 TIMES");
		System.out.println("-------------------------------------------------------------");

		//VIEWER1 GO NEXT TEXT 3 TIMES BUT THERE IS NO 3 TEXT AFTER CURRENT SO IT GOES 
		//FIRST TEXT DATA AND KEEPS GO IN THERE
		v1.next("text");
		v1.next("text");
		v1.next("text");
		n_play1 = (non_playable)v1.currently_playing();
		n_play1.non_playable_info();
		
		
		//OBSERVER UN-REGISTERED TO LIST SO IT CAN'T OBSERVE THE SUBJECT
		ds.remove_observer(p1);
		ds.add(new video("Star Wars: Chapter IV (1977)", 121.30,2000, "Director: George Lucas"));
		ds.add(new video("Harry Potter and the Philosopher's Stone (2001)", 162.40,2000, " Chris Columbus"));

		System.out.println("After Player1 un-registered\nPlayer1");
		p1.show_list();
		System.out.println("\nPlayer2");
		p2.show_list();	
	}
}