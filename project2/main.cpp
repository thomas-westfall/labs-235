
#include "PlayList.cpp"
#include "Song.cpp"
#include <iostream>

int main()
{
	//**********Test Song************//

	// instantiate 5 songs

	Song song1;

	song1.setTitle("title 1");

	song1.setAuthor("author 1");

	song1.setAlbum("album 1");

	Song song2("title 2", "author 2", "album 2");

	Song song3("title 3", "author 3", "album 3");

	Song song4("title 4", "author 4", "album 4");

	Song song5("title 5", "author 5", "album 5");

	// output song information

	std::cout << "The first song is: " << song1.getTitle() << ", " << song1.getAuthor() << ", "
	          << song1.getAlbum() << '\n';

	std::cout << "The second song is: " << song2.getTitle() << ", " << song2.getAuthor() << ", "
	          << song2.getAlbum() << '\n';

	std::cout << "The third song is: " << song3.getTitle() << ", " << song3.getAuthor() << ", "
	          << song3.getAlbum() << '\n';

	std::cout << "The fourth song is: " << song4.getTitle() << ", " << song4.getAuthor() << ", "
	          << song4.getAlbum() << '\n'
	          << '\n';

	//************* Test PlayList*************//

	// instantiate PlayList and add Songs to it

	PlayList myPlayList(song1);

	myPlayList.addSong(song2);

	myPlayList.addSong(song3);

	myPlayList.displayPlayList();

	std::cout << "Playlist now holds " << myPlayList.getNumberOfSongs() << " songs\n\n";

	myPlayList.addSong(song1);

	myPlayList.displayPlayList();

	std::cout << '\n';

	myPlayList.addSong(song4);

	myPlayList.displayPlayList();

	std::cout << '\n';

	myPlayList.addSong(song5);

	myPlayList.displayPlayList();

	std::cout << '\n';

	myPlayList.removeSong(song2);

	myPlayList.displayPlayList();

	std::cout << '\n';

	myPlayList.removeSong(song3);

	myPlayList.displayPlayList();

	std::cout << '\n';

	myPlayList.clearPlayList();

	myPlayList.displayPlayList();

	std::cout << myPlayList.isEmpty() << '\n';

	return 0;
}
