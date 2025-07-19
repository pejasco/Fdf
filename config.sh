sudo apt update
sudo apt install -y build-essential libx11-dev libxext-dev libbsd-dev zlib1g-dev

# Clone MinilibX directly
rm -rf lib/minilibx-linux
mkdir -p lib
git clone https://github.com/42Paris/minilibx-linux.git lib/minilibx-linux
