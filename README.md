# calendario
Um arquivo chamado README.md que lista os membros do grupo, resume seu programa e explica quaisquer problemas que você teve.

GRUPO: Gabriel de Assis, Leandro Kavgias, Renan Hammerschlag.

Resumo do nosso programa:

O nosso código cria um calendário interativo onde é possível visualizar, inserir e verificar agendamentos feitos por nossos usuários. Ele começa definindo variáveis para armazenar informações sobre o ano, mês, dia da semana e se o ano é bissexto. Além disso, há arrays para armazenar o número de dias em cada mês, os dias da semana e os meses do ano.

Nossa função inicializarAgendamentos() armazena os agendamentos para cada dia do ano. A função mostrarCalendario() imprime o calendário do ano especificado, mostrando os dias de cada mês. Os dias são impressos em sequência, ele começa pelo dia da semana em que o 1º de janeiro cai, ele permanece na sequência correta mesmo o ano sendo bissexto ou não.

A função inserirAgendamento() permite o usuário a inserir um agendamento para um determinado dia do mês, verificando se há conflitos com outros agendamentos (Não poderá ter mais do que 5 agendamentos). Se houver, uma mensagem de erro éexibida; caso contrário, o agendamento é realizado com sucesso.

E por fim, a função mostrarCalendarioAgendado() exibe o calendário apenas com os dias agendados para o ano especificado pelo usuário. Em seguida, exibe um menu interativo para visualização, inserção e verificação de agendamentos até que o usuário opte por sair do sistema.

Problemas que tivermos:

1- Calendario sequencial: Todos os dias estavam na mesma ordem em todos os meses. (Concluido)

1.1- Calendario: No mes de Fevereito para Março possui um erro que não conseguimos resolver, (ex: ano n bissexto: 28 de feveiro cai na quinta, 1 de março esta caindo no sábado. O mesmo vale para o ano bissexto: 29 de feveiro cai na sexta, 1 de março esta caindo no domingo). (Concluido)

2- Tivemos problema em relação ao calendario de agendamentos, não sabíamos se botavamos todos os dias e apenas anulávamos os dias agendados e printava na tela. (Resolvido)

3- Ano bissexto: Por o ano ser bissexto ou não, tivemos q criar um If para se caso o ano n fosse, fevereiro teria 28 dias e se fosse bissexto, fevereiro retorna o ultimo dia como 29. (Resolvido)

3.1- Ano bissexto: Se caso o usuário falasse que o ano não era bissexto, mas colocasse o ano 2024, o Console mostrava q feveriro pussuia 28 dias. Porem agr ele verifica se o ano é ou não bissexto antes de mostrar o calendário. (Resolvido)

4- Calendário de Agendados: O único erro q tivemos referênte ao calendário de agendamentos é em questão de estética, pois n conseguimos deixar ele certinho assim como fizemos no primeiro, mas em questão de funcionalidade, ele mostra as datas certas de todos q se agendaram (caso n passe de 5 agendamentos), se passar, apenas os 5 primeiros agendados que serão mostrados no calendário. (Estético: N Resovido, Funcionalidade: OK)
