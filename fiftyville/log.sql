-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports
WHERE day = 28 AND month = 7
AND street = "Humphrey Street";
-- Checking details of what happened in the day of the crime

SELECT name, transcript FROM interviews
WHERE day = 28 and month = 7;

-- checking their interviews

-- the crime_scene_reports say that the 3 witness mentioned something about bakery
SELECT name, transcript FROM interviews
WHERE day = 28 AND month = 7
AND transcript LIKE "%bakery%";
-- witness are Eugene, Ruth, Raymond


-- Eugene sayed That the thief was withdrawing money from the ATM on Leggett Street
SELECT account_number, amount
FROM atm_transactions
WHERE day = 28 AND month = 7
AND atm_location = "Leggett Street"
AND transaction_type = 'withdraw';

SELECT name, atm_transactions.amount
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.day = 28
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.atm_location = 'Leggett Street'
AND atm_transactions.transaction_type = 'withdraw';
-- Seeing the name of all persons that withdrawing money in that day

-- Raymond gave clues that the thief ordered the earliest flight
SELECT abbreviation, full_name, city
FROM airports
WHERE city = 'Fiftyville';

-- Finding the flights on July 29 from Fiftyville airport
SELECT flights.id, full_name, city, flights.hour, flights.minute
FROM airports
JOIN flights
ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id =
(SELECT id
FROM airports
WHERE city = 'Fiftyville')
AND flights.year = 2021
AND flights.month = 7
AND flights.day = 29
ORDER BY flights.hour, flights.minute;
-- First flight comes out to be at 8:20 to LaGuardia Airport in New York City (Flight id- 36). This could be the place where the thief went to.

-- Checking the list of passengers in that flight. Putting them all in 'Suspect List'. Ordering the names according to their passport numbers.
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id
WHERE flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND flights.hour = 8
AND flights.minute = 20
ORDER BY passengers.passport_number;
-- Checking the phone call records to find the person who bought the tickets.
-- Firstly, checking the possible names of the caller, and putting these names in the 'Suspect List'. Ordering them according to the durations of the calls.
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;
-- Secondly, checking the possible names of the call-receiver. Ordering them according to the durations of the calls.
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;


-- Ruth gave clues- The thief drove away in a car from the bakery, within 10 minutes from the theft. SO, checking the license plates of cars within that time frame. Then, checking out the names of those cars' owners. They could be suspects.
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.activity = 'exit'
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
ORDER BY bakery_security_logs.minute;

-- Bruce probably is the thief because he appear in all the 4 list that i checked.
-- He must have escaped to the New York City, because he took the New York City flight.
-- Robin must be the accomplice who purchased the flight ticket.