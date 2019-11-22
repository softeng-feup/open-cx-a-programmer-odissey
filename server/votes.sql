begin transaction;

drop table if exists votes;
create table votes (
    question text primary key, 
    yes_votes int, 
    no_votes int
);

commit transaction;
