#include "WatchList.h"

// Increment the likes for the movie
void WatchList::incrementLikes() {
    setLikes(getLikes() + 1);
}
