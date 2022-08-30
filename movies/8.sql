SELECT name FROM people JOIN stars ON stars.person_id = people.id Join movies ON movies.id =
stars.movie_id WHERE title LIKE "Toy Story";