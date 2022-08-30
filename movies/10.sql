SELECT name FROM people 
JOIN directors ON directors.person_id = people.id
JOIN ratings ON ratings.movie_id = directors.movie_id
WHERE rating >= 9;

-- select name from people
-- join directors on directors.person_id = people.id
-- join ratings on directors.movie_id = ratings.movie_id
-- where rating >= 9.0;