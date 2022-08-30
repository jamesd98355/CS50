SELECT title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE name LIKE "Johnny Depp"
AND movie_id IN
(SELECT movie_id from stars
JOIN people ON people.id = stars.person_id
WHERE name LIKE "Helena Bonham Carter");