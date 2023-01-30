# Importando API
#
# INICIO
# bot_script

# Importando API
source ShellBot.sh

# Token do bot
bot_token='5930363802:AAH1VMsE95atmqlp9Eblrzjpe_cMR-czR-8'

# Inicializando o bot
ShellBot.init --token "$bot_token"

# Imprime o username do bot.
ShellBot.username

#pega a data
DATE=$(date +"%Y-%m-%d_%H%M%S")

# loop
while :
do
    # Obtendo atualizações
    ShellBot.getUpdates --limit 100 --offset $(ShellBot.OffsetNext) --timeout 30

    # Lista os índices das atualizações.
    for id in $(ShellBot.ListUpdates)
    do
    # Bloco de instruções
    (
        # Verifica se a mensagem é do tipo comando.
        if [[ ${message_entities_type[$id]} == bot_command ]]
        then
            # Remove o sufixo contendo o username do bot e o '@' inclusive, extraindo somente o comando.
            case ${message_text[$id]%%@*} in
                '/info')   
                    
                    # Envia mensagem ao remetente.
                    ShellBot.sendMessage --chat_id ${message_chat_id[$id]} \
                                         --text "Olá *${message_from_first_name[$id]}*, segue info do seu pet" \
                                         --parse_mode markdown
                    fswebcam -r 1920x1080 --no-banner /home/gabriela/Desktop/$DATE.jpg

                    curl -F "chat_id=${message_chat_id[$id]}" -F "photo=@/home/gabriela/Desktop/$DATE.jpg" https://api.telegram.org/bot5930363802:AAH1VMsE95atmqlp9Eblrzjpe_cMR-czR-8/sendphoto
                    
                    python3 tempUmid.py
                    
                    var=$(cat dadostempumid.txt)
                    
                    ShellBot.sendMessage --chat_id ${message_chat_id[$id]} \
                                         --text "{$var}" \
                                         --parse_mode markdown
                    
                    
                    
                ;;
            esac
         fi
    ) & # Thread
    done
done
