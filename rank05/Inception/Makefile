NAME := inception
LOGIN := rnishi
COMPOSE_FILE := srcs/docker-compose.yml
ENV_FILE := srcs/.env
DATA_ROOT ?= /home/$(LOGIN)/data
DATA_DIR := $(DATA_ROOT)
COMPOSE := docker compose -f $(COMPOSE_FILE) --env-file $(ENV_FILE)
DEV_DATA_ROOT := $(PWD)/.data
DEV_COMPOSE := DATA_ROOT="$(DEV_DATA_ROOT)" $(COMPOSE)

.PHONY: all build up down logs ps clean fclean re \
	dev-build dev-up dev-down dev-logs dev-ps dev-clean dev-fclean dev-re

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

dev-build:
	@mkdir -p $(DEV_DATA_ROOT)/mariadb $(DEV_DATA_ROOT)/wordpress
	$(DEV_COMPOSE) build

dev-up:
	@mkdir -p $(DEV_DATA_ROOT)/mariadb $(DEV_DATA_ROOT)/wordpress
	$(DEV_COMPOSE) up -d --build

dev-down:
	$(DEV_COMPOSE) down

dev-logs:
	$(DEV_COMPOSE) logs -f

dev-ps:
	$(DEV_COMPOSE) ps

dev-clean:
	$(DEV_COMPOSE) down --remove-orphans

dev-fclean:
	$(DEV_COMPOSE) down --remove-orphans --volumes --rmi local
	rm -rf $(DEV_DATA_ROOT)

dev-re: dev-fclean dev-up
