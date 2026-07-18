#!/usr/bin/env bash

CURRENT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

PLUGIN=" #($CURRENT_DIR/bin/tmux-power-linux-x86_64)"

CURRENT_STATUS="$(tmux show -gv status-right)"

case "$CURRENT_STATUS" in
	*"$CURRENT_DIR/bin/tmux-power-linux-x86_64"*)
		;;
	*)
		tmux set -ag status-right "$PLUGIN"
		;;
esac
