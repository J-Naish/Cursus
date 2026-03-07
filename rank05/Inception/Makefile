NAME := inception
LOGIN := rnishi
COMPOSE_FILE := srcs/docker-compose.yml
ENV_FILE := srcs/.env
DATA_ROOT ?= /home/$(LOGIN)/data
DATA_DIR := $(DATA_ROOT)
COMPOSE := docker compose -f $(COMPOSE_FILE) --env-file $(ENV_FILE)

.PHONY: all build up down logs ps clean fclean re

all: up

build:
	@mkdir -p $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress
	$(COMPOSE) build

up:
	@mkdir -p $(DATA_DIR)/mariadb $(DATA_DIR)/wordpress
	$(COMPOSE) up -d --build

down:
	$(COMPOSE) down

logs:
	$(COMPOSE) logs -f

ps:
	$(COMPOSE) ps

clean:
	$(COMPOSE) down --remove-orphans

fclean:
	$(COMPOSE) down --remove-orphans --volumes --rmi local

re: fclean up
