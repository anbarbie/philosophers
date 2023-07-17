# philosophers

This project is a simulation of the Dining Philosophers problem, a classic synchronization problem in computer science. The simulation involves a group of philosophers sitting at a round table, taking turns to eat, think, or sleep. The goal is to ensure that every philosopher can eat without starving and avoid any deadlocks or inconsistencies.

## Overview

- One or more philosophers sit at a round table with a large bowl of spaghetti in the middle.
- The philosophers alternate between three states: eating, thinking, and sleeping.
- While a philosopher is eating, they cannot think or sleep; while thinking, they cannot eat or sleep; and while sleeping, they cannot eat or think.
- There are as many forks on the table as there are philosophers.
- To eat, a philosopher must pick up the fork on their left and the fork on their right.
- After finishing their meal, the philosopher puts the forks back on the table and starts sleeping. Once awake, they resume thinking.
- The simulation stops when a philosopher dies of starvation.

## Program Requirements

- Your program must comply with the following rules:
  - Global variables are forbidden.
  - The program should take the following arguments:
    - `number_of_philosophers`: The total number of philosophers and forks.
    - `time_to_die`: The maximum time in milliseconds for a philosopher to start eating since their last meal or the beginning of the simulation. If this time is exceeded, the philosopher dies.
    - `time_to_eat`: The time in milliseconds for a philosopher to finish their meal while holding two forks.
    - `time_to_sleep`: The time in milliseconds for a philosopher to spend sleeping.
    - `number_of_times_each_philosopher_must_eat` (optional): If specified, all philosophers must eat at least this number of times before the simulation stops. If not specified, the simulation stops when a philosopher dies.

- Each philosopher is assigned a number ranging from 1 to `number_of_philosophers`.
- Philosopher number 1 sits next to philosopher number `number_of_philosophers`, and any other philosopher number N sits between philosopher number N-1 and N+1.

## Logging

- The program should provide clear and formatted logs of each philosopher's state changes, following the format:
  - `timestamp_in_ms X has taken a fork`
  - `timestamp_in_ms X is eating`
  - `timestamp_in_ms X is sleeping`
  - `timestamp_in_ms X is thinking`
  - `timestamp_in_ms X died`

- Replace `timestamp_in_ms` with the current timestamp in milliseconds, and `X` with the philosopher number.
- Ensure that the displayed state messages are not mixed up with other messages.
- A message announcing a philosopher's death should be displayed no more than 10 ms after the actual time of death.

Remember, the goal is to ensure that philosophers can eat without starving, avoid deadlocks, and maintain consistent state changes throughout the simulation.
