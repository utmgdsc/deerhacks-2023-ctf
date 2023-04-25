#!/bin/bash

echo -e "$(./num_guess_sol)" | nc 127.0.0.1 1337
