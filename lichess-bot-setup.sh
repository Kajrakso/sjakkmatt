#!/bin/bash

# First you need to create a .env file with the following contents:
# LICHESS_BOT_TOKEN=xxxxxxxxxxxxxxxxxxx

cd "$(dirname "$0")"

# Load environment variables from .env
if [ -f .env ]; then
    source .env
else
    echo ".env file not found! Create it and store the LICHESS_BOT_TOKEN here"
    exit 1
fi

# Check that we got the necessary files and variables
if [ -z "$LICHESS_BOT_TOKEN" ]; then
    echo "LICHESS_BOT_TOKEN is not set in .env!"
    exit 1
fi


if [ ! -d lichess-bot ]; then
    git clone https://github.com/lichess-bot-devs/lichess-bot.git

    cd lichess-bot

    # Create virtual environment
    python3 -m venv venv || { echo "Failed to create virtualenv. Check Python installation."; exit 1; }

    source ./venv/bin/activate
    python3 -m pip install --upgrade pip
    python3 -m pip install -r requirements.txt

    cd ..
fi 

if [ ! -f lichess-bot-config.yml ]; then
    echo "Template config file 'lichess-bot-config.yml' not found!"
    exit 1
fi

sed "s/xxxxxxxxxxxxxxxxxxxxxx/$LICHESS_BOT_TOKEN/" lichess-bot-config.yml > lichess-bot/config.yml
echo "Config generated in lichess-bot/config.yml"
