# sjakkmatt

My attempt at a chess bot.

*Work in progress*

## Usage

`sjakkmatt` speaks [UCI](https://www.wbec-ridderkerk.nl/html/UCIProtocol.html),
so just plug it into any chess GUI and you should be good to go.

## Build from source

Run 

```sh
make sjakkmatt
```

to build `sjakkmatt` and 

```sh
make test
```

to run the tests (you need [Criterion](https://github.com/Snaipe/Criterion) for these).

## Lichess bot

I have made a lichess bot that uses `sjakkmatt`
as it's engine. If it is running you can challenge
it for a game or two [here](https://lichess.org/@/sjakkmatt-bot).

You can us `sjakkmatt` with your own lichess bot by
creating a `.env` file in the project root with the lichess bot token:

```sh
LICHESS_BOT_TOKEN=xxxxxxxxxxxxxxxxxxx
```

Replace `your_lichess_bot_token_here` with your actual token.
**Important:** Never share your token publicly or commit the `.env` file to version control. It's already included in `.gitignore` by default.

Then run

```sh
make lichess-bot
```

to setup the bot, and

```sh
make run-bot
```

to run it.
