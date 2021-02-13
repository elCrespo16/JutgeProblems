#include "Player.hh"
#include <string>


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Monka$


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
  #define whole_map 61
  #define No_cell CellTypeSize
  #define Every_one 5
  #define IA -1
  #define No_one -2

  map<int,string> dwa_map;
  map<int,string> wiz_map;
  int last_pillo = -1;

  bool changed_strat = false;
  int dwa_run_hp = 45; 
  int Next_strat_round = 150;
  int Attack_range = 4;
  int Attack_range_rage = 7;
  int Run_range = 3;
  int Treasure_range = 9;
  int No_more_treasures = 65;
  struct celda {
      bool visited;
      Dir sig;
      int dist;
  };
  
  typedef vector<int> v;
  typedef vector < vector<celda> > M_visited;
  typedef queue <Pos> to_visit;
  typedef vector < vector<bool> > M_vis_barl;
  /*
  Funcion para comprobar que la posicion es correcta
  */
  bool cell_ok(Pos p, bool no_block, bool no_rock){
    Cell a = cell(p);
    return not (a.type == Abyss or a.type == Granite or (no_block and a.id != -1 and unit(a.id).player == me()) or (no_rock and a.type == Rock));
  }
  /*
  Funcion para enviar la condicion contraria
  */
  Dir contr_dir(Dir d){
    if(d == Bottom)return Top;
    if(d == Top)return Bottom;
    if(d == Left)return Right;
    if(d == Right)return Left;
    if(d == BR)return TL;
    if(d == TL)return BR;
    if(d == RT)return LB;
    if(d == LB)return RT;
    return None;
  }
  /*
  Funcion para comprobar si he encontrado el objetivo
  p = Posicion a comprobar
  target = string con los objetivos a buscar
  player_target = jugador al que quiero buscar
  cell_type = tipo de celda que busco
  */
  bool target_located(Pos p, string target, int player_target , CellType cell_target){
      if(cell_target != No_cell){
        if(cell_target == cell(p).type) {
            return cell(p).owner != me();
        }
        return false;
      }
      if(target[0] != 'n'){
        int s_size = target.size();
        if(target[0] == 'x')return cell(p).treasure;
        for(int i = 0;i < s_size;++i){
	        UnitType entity = char2ut(target[i]);
	        if(cell(p).id != -1 and unit(cell(p).id).type == entity and player_target != No_one) {
            if(player_target == Every_one){
              return unit(cell(p).id).player != me();
            }
            if(player_target == unit(cell(p).id).player)return true;
            return false;
          }
        }
      }
      return false;
  }

  /*
    BFS para casi todo
    Id = id del personaje que quiere buscar
    target = Char que indica que busco (w wizard, d dwarf, b barlog, t troll, x treasure, o orc, n nadie)
    player target = numero de player a quien quiero buscar, -1 si a la IA
    cell_target = tipo de celda que busco (No_cell para ninguna celda)
    dist = distancia max que busco (Whole_map para todo el game)
    no_rock = quiero ignorar rock
    no_enemy = ignoro celdas con enemigos

  */
  Dir bfs(int id, string target, int player_target , CellType cell_target, int dist, bool no_rock, bool no_block){
    Pos ini = unit(id).pos, fin;
    bool is_wizard = unit(id).type == Wizard;
    fin = ini;
    Pos p = ini;
    if(pos_ok(p)){
      celda defa;
      defa.visited = false;
      defa.sig = None;
      defa.dist = 0;
      M_visited m_vis (rows(), vector<celda> (cols(),defa));
      to_visit t_vis;
      bool found = false;
      m_vis[p.i][p.j].visited = true;
      t_vis.push(p);
      while(not t_vis.empty() and not found and m_vis[t_vis.front().i][t_vis.front().j].dist < dist){
        p = t_vis.front();
        t_vis.pop();
        int dis = m_vis[p.i][p.j].dist;
        Pos d = p;
        vector<Dir> ant (8);
        ant = {Bottom, Right, Top, Left, BR ,RT,  TL,  LB};
        for(int i = 0;i < 8;++i){
          d = p + ant[i];
          if(is_wizard and i >= 4)break;
          if(pos_ok(d) and cell_ok (d,no_block,no_rock) and not m_vis[d.i][d.j].visited){
            if(target_located(d,target,player_target,cell_target) ){
              found = true;
              fin = d;
            }
            m_vis[d.i][d.j].visited = true;
            m_vis[d.i][d.j].sig = ant[i];
	          m_vis[d.i][d.j].dist = dis + 1;
            t_vis.push(d);
          }
        }
      }
      if(fin == ini)return None;
      stack<Dir> res;
      while(fin != ini){
        res.push(m_vis[fin.i][fin.j].sig);
        fin += contr_dir(m_vis[fin.i][fin.j].sig);
      }
      return res.top();
    }
    return None;
  }
  /*
  Funcion para comprobar que la posicion es correcta modo barlog
  */
  bool cell_ok_barl(Pos& p){
    Cell a = cell(p);
    return not a.type == Outside;
  }
  /*
  Funcion para comprobar si he encontrado el objetivo modo barlog
  */
  /*
  bool target_located_barl(Pos& p){
      if(cell(p).id != -1){
          if(unit(cell(p).id).type == Dwarf or unit(cell(p).id).type == Wizard)return true;
      }
      return false;
  }

  int bfs_barlog(int id){
    Pos ini = unit(id).pos, fin;
    fin = ini;
    Pos p = ini;
    if(pos_ok(p)){
      M_vis_barl m_vis (rows(), vector<bool> (cols(),false));
      to_visit t_vis;
      bool found = false;
      m_vis[p.i][p.j] = true;
      t_vis.push(p);
      while(not t_vis.empty() and not found){
        p = t_vis.front();
        t_vis.pop();
        Pos d;
        vector<Dir> ant (4);
        ant = {Bottom, Right, Top, Left};
        for(int i = 0;i < 4;++i){
          d = p + ant[i];
          if(pos_ok(d) and cell_ok_barl (d) and not m_vis[d.i][d.j]){
            if(target_located_barl(d)){
              if(unit(cell(d).id).player == me()){
                  return cell(d).id;
              }
              found = true;
            }
            m_vis[d.i][d.j] = true;
            t_vis.push(d);
          }
        }
      }
    }
    return -1;
  }
  */
  /*
  Asigna a mis unidades la funcion de pillo o de huida
  si son el objetivo del barlog
  */
 /*
  void search_for_pillo(){
    int barl_id = balrog_id();
    int id = bfs_barlog(barl_id);
    if(id != -1 and id != last_pillo){
      map<int,string>::iterator it;
      it = dwa_map.find(id);
      if(it != dwa_map.end()){
        (*it).second = "Pillo";
        if(last_pillo != -1){
          it = dwa_map.find(last_pillo);
          (*it).second = "Idle";
        }
        last_pillo = id;
      }
      else {
        if(last_pillo != -1){
            it = dwa_map.find(last_pillo);
            (*it).second = "Idle";
            it = wiz_map.find(id);
            last_pillo = -1;
            if(it != wiz_map.end())(*it).second = "RunB";
        }
      }
      
    }
  }
  */

  bool target_located_smart(Pos& p,int& id){
    if(cell(p).id != -1){
      if((unit(cell(p).id).type == Dwarf or unit(cell(p).id).type == Wizard or unit(cell(p).id).type == Orc) and unit(cell(p).id).player != me()) {
        if(bfs(cell(p).id,"dw",Every_one,No_cell,2,false,false) == None)return true;
        else {
          return unit(cell(p).id).health <= unit(id).health or unit(cell(p).id).health <= 30;
        }
      }
    }
    return false;
  }

  Dir bfs_4_attack (int& id, int& dist){
    Pos ini = unit(id).pos, fin;
    fin = ini;
    Pos p = ini;
    if(pos_ok(p)){
      celda defa;
      defa.visited = false;
      defa.sig = None;
      defa.dist = 0;
      M_visited m_vis (rows(), vector<celda> (cols(),defa));
      to_visit t_vis;
      bool found = false;
      m_vis[p.i][p.j].visited = true;
      t_vis.push(p);
      while(not t_vis.empty() and not found and m_vis[t_vis.front().i][t_vis.front().j].dist < dist){
        p = t_vis.front();
        t_vis.pop();
        int dis = m_vis[p.i][p.j].dist;
        Pos d = p;
        vector<Dir> ant (8);
        ant = {Bottom, Right, Top, Left, BR ,RT,  TL,  LB};
        for(int i = 0;i < 8;++i){
          d = p + ant[i];
          if(pos_ok(d) and cell_ok (d,true,true) and not m_vis[d.i][d.j].visited){
            if(target_located_smart(d,id)){
              found = true;
              fin = d;
            }
            m_vis[d.i][d.j].visited = true;
            m_vis[d.i][d.j].sig = ant[i];
	          m_vis[d.i][d.j].dist = dis + 1;
            t_vis.push(d);
          }
        }
      }
      if(fin == ini)return None;
      stack<Dir> res;
      while(fin != ini){
        res.push(m_vis[fin.i][fin.j].sig);
        fin += contr_dir(m_vis[fin.i][fin.j].sig);
      }
      return res.top();
    }
    return None;
  }

  Dir bfs_pillo(int id, string target, int player_target , CellType cell_target, int dist, bool no_rock, bool no_block,M_visited& m_vis ){
    Pos ini = unit(id).pos, fin;
    fin = ini;
    Pos p = ini;
    if(pos_ok(p)){
      to_visit t_vis;
      bool found = false;
      m_vis[p.i][p.j].visited = true;
      t_vis.push(p);
      while(not t_vis.empty() and not found and m_vis[t_vis.front().i][t_vis.front().j].dist < dist){
        p = t_vis.front();
        t_vis.pop();
        int dis = m_vis[p.i][p.j].dist;
        Pos d = p;
        vector<Dir> ant (8);
        ant = {Bottom, Right, Top, Left, BR ,RT,  TL,  LB};
        for(int i = 0;i < 8;++i){
          d = p + ant[i];
          if(pos_ok(d) and cell_ok (d,no_block,no_rock) and not m_vis[d.i][d.j].visited){
            if(target_located(d,target,player_target,cell_target) and dist > 2){
              found = true;
              fin = d;
            }
            m_vis[d.i][d.j].visited = true;
            m_vis[d.i][d.j].sig = ant[i];
	          m_vis[d.i][d.j].dist = dis + 1;
            t_vis.push(d);
          }
        }
      }
      if(fin == ini)return None;
      stack<Dir> res;
      while(fin != ini){
        res.push(m_vis[fin.i][fin.j].sig);
        fin += contr_dir(m_vis[fin.i][fin.j].sig);
      }
      return res.top();
    }
    return None;
  }


  void fill_barlog(M_visited m_vis){
      Pos p = unit(balrog_id()).pos, d;
      vector<Dir> ant (8);
      ant = {Bottom, Right, Top, Left, BR ,RT,  TL,  LB};
      for(int i = 0;i < 8;++i){
          d = p + ant[i];
          m_vis[d.i][d.j].visited = true;
      }
  }
  /*
  Funcion para cambiar el estado de cada Dwarf
  Posibles estados:
  - Run
  - Finder
  - Injured
  - Pillo
  - Idle
  - Conqueror
  */
  void change_state_dwa(map<int,string>::iterator it){
    int id = (*it).first;
    string state = (*it).second;
    Dir next_move = None;
    /*
    //Pillo
    if (state == "Pillo"){
      int focus = me();
      int my_points = nb_cells(me()) + nb_treasures(me());
      int max_points = my_points;
      int max_unit = -1;
      for(int i = 0;i < nb_players();++i){
        if(i != me()){
          int points = nb_cells(i) + nb_treasures(i);
          if(points > my_points) {
           if(points > max_points){
              focus = i;
              max_points = points;
            }
          }
          else {
            if(max_points == my_points){
              int player_units = wizards(i).size() + dwarves(i).size();
              if(max_unit < player_units){
                focus = i;
                max_unit = player_units;
              }
            }
          }
        }
      }
      celda defa;
      defa.visited = false;
      defa.sig = None;
      defa.dist = 0;
      
      command(id,bfs_pillo(id,"dw",focus,No_cell,whole_map,true,true,m_vis));
      return;
    }
    */
    //Idle
    if(state == "Idle"){
      //Run
      next_move = bfs(id,"tb",IA,No_cell,Run_range,false,true);
      if(next_move != None){
        (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
      }
      //Attack
      if(round() <= Next_strat_round) next_move = bfs_4_attack(id,Attack_range);
      else next_move = bfs_4_attack(id,Attack_range_rage);
      if(next_move != None){
        (*it).second = "Attack";
         
        command(id,next_move);
        return;
      }
      //Injured
      else if(unit(id).health < dwa_run_hp){
        (*it).second = "Injured";
        command(id,bfs(id,"w",me(),No_cell,whole_map,true,false));
        return;
      }
      //Buscador de tesoros
      next_move = bfs(id,"x",No_one,No_cell,Treasure_range,false,true);
      if(next_move != None and round() <= Next_strat_round){
        (*it).second = "Finder";
         
        command(id,next_move);
        return;
      }
      //Conquer
      else {
        (*it).second = "Conqueror";
        command(id,bfs(id,"n",Every_one,Cave,whole_map,false,true));
        return;
      }
    }
    //Attack
    if(state == "Attack"){
        next_move = bfs(id,"tb",IA,No_cell,Run_range,false,true);
      if(next_move != None){
        (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
      }
      //Attack
      if(round() <= Next_strat_round) next_move = bfs_4_attack(id,Attack_range);
      else next_move = bfs_4_attack(id,Attack_range_rage);
      if(next_move != None){
         command(id,next_move);
        return;
      }
      //Injured
      else if(unit(id).health < dwa_run_hp){
        (*it).second = "Injured";
        command(id,bfs(id,"w",me(),No_cell,whole_map,true,false));
        return;
      }
      //Buscador de tesoros
      next_move = bfs(id,"x",No_one,No_cell,Treasure_range,false,true);
      if(next_move != None and round() <= Next_strat_round){
        (*it).second = "Finder";
         
        command(id,next_move);
        return;
      }
      //Conquer
      else {
        (*it).second = "Conqueror";
        command(id,bfs(id,"n",Every_one,Cave,whole_map,false,true));
        return;
      }
    }
    //Run
    if(state == "Run"){
      next_move = bfs(id,"tb",IA,No_cell,Run_range,false,true);
      if(next_move == None){
        if(round() <= Next_strat_round) next_move = bfs_4_attack(id,Attack_range);
        else next_move = bfs_4_attack(id,Attack_range_rage);
        if(next_move != None){
          (*it).second = "Attack";
           
          command(id,next_move);
          return;
        }
        //Injured
        else if(next_move == None and unit(id).health < dwa_run_hp){
          (*it).second = "Injured";
          command(id,bfs(id,"w",me(),No_cell,whole_map,true,false));
          return;
        }
        //Buscador de tesoros
        next_move = bfs(id,"x",No_one,No_cell,Treasure_range,false,true);
        if(next_move != None and round() <= Next_strat_round){
          (*it).second = "Finder";
           
          command(id,next_move);
          return;
        }
        //Conquer
        else {
          (*it).second = "Conqueror";
          command(id,bfs(id,"n",Every_one,Cave,whole_map,false,true));
          return;
        }
      }
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
    }
    //Finder
    if(state == "Finder"){
      next_move = bfs(id,"tb",IA,No_cell,Run_range,false,true);
      if(next_move != None){
        (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
      }
      if(round() <= Next_strat_round) next_move = bfs_4_attack(id,Attack_range);
      else next_move = bfs_4_attack(id,Attack_range_rage);
      if(next_move != None){
        (*it).second = "Attack";
         
        command(id,next_move);
        return;
      }
      //Injured
      else if(unit(id).health < dwa_run_hp){
        (*it).second = "Injured";
        command(id,bfs(id,"w",me(),No_cell,whole_map,true,false));
        return;
      }
      //Buscador de tesoros
      next_move = bfs(id,"x",No_one,No_cell,Treasure_range,false,true);
      if(next_move != None and round() <= Next_strat_round){
         
        command(id,next_move);
        return;
      }
      //Conquer
      else {
        (*it).second = "Conqueror";
        command(id,bfs(id,"n",Every_one,Cave,whole_map,false,true));
        return;
      }
    }
    //Injured
    if(state == "Injured"){
      next_move = bfs(id,"tb",IA,No_cell,Run_range,false,true);
      if(next_move != None){
        (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
      }
      if(round() <= Next_strat_round) next_move = bfs_4_attack(id,Attack_range);
      else next_move = bfs_4_attack(id,Attack_range_rage);
      if(next_move != None){
        (*it).second = "Attack";
        command(id,next_move);
        return;
      }
      //Injured
      if(unit(id).health < dwa_run_hp){
        command(id,bfs(id,"w",me(),No_cell,whole_map,true,false));
        return;
      }
      else {
         next_move = bfs(id,"x",No_one,No_cell,Treasure_range,false,true);
      if(next_move != None and round() <= Next_strat_round){
         
        command(id,next_move);
        return;
      }
      //Conquer
      else {
        (*it).second = "Conqueror";
        command(id,bfs(id,"n",Every_one,Cave,whole_map,false,true));
        return;
      } 
      }
    }
    //Conqueror
    if(state == "Conqueror"){
      //Run
      next_move = bfs(id,"tb",IA,No_cell,Run_range,false,true);
      if(next_move != None){
       (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
      }
      //Attack
      if(round() <= Next_strat_round) next_move = bfs_4_attack(id,Attack_range);
      else next_move = bfs_4_attack(id,Attack_range_rage);
      if(next_move != None){
        (*it).second = "Attack";
         
        command(id,next_move);
        return;
      }
      //Injured
      else if(unit(id).health < dwa_run_hp){
        (*it).second = "Injured";
        command(id,bfs(id,"w",me(),No_cell,whole_map,true,false));
        return;
      }
      //Buscador de tesoros
      next_move = bfs(id,"x",No_one,No_cell,Treasure_range,false,true);
      if(next_move != None and round() <= Next_strat_round){
        (*it).second = "Finder";
         
        command(id,next_move);
        return;
      }
      //Conquer
      else {
        command(id,bfs(id,"n",Every_one,Cave,whole_map,false,true));
        return;
      }
    }
  }
  /*
  Funcion para cambiar el estado de cada Wizards
  Posibles estados:
  - Run
  - Healer
  - Injured
  - RunB
  */
  void change_state_wiz(map<int,string>::iterator& it){
    int id = (*it).first;
    string state = (*it).second;
    Dir next_move = None;
    //Run
    /*if(state == "RunB"){
        if(cell(unit(id).pos).type == Outside){
            if(unit(id).health < wizards_health()){
                next_move = bfs(id,"w",me(),No_cell,whole_map,true,false);
                (*it).second = "Injured";
                command(id,next_move);
                return;
            }
            else {
                next_move = bfs(id,"d",me(),No_cell,whole_map,true,false);
                (*it).second = "Healer";
                command(id,next_move);
                return;
            }
        }
        command(id, bfs(id,"n",No_one,Outside,whole_map,true,true));
    }
    */
    if(state == "Run"){
      next_move = bfs(id,"tb",IA,No_cell,Run_range,true,false);
      if(next_move == None){
        if(unit(id).health < wizards_health()){
          next_move = bfs(id,"w",me(),No_cell,whole_map,true,false);
          (*it).second = "Injured";
          command(id,next_move);
          return;
        }
        else {
          next_move = bfs(id,"d",me(),No_cell,whole_map,true,false);
          (*it).second = "Healer";
           
          command(id,next_move);
          return;
        }
      }
      (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
    }
    //Buscar aliados
    if(state == "Healer"){
      //Run
      next_move = bfs(id,"tb",IA,No_cell,Run_range,true,false);
      if(next_move != None){
        (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
      }
      //Herido
      if(unit(id).health < wizards_health()){
        next_move = bfs(id,"w",me(),No_cell,whole_map,true,false);
        command(id,next_move);
        (*it).second = "Injured";
        return;
      }
      //Healer
      else {
        next_move = bfs(id,"d",me(),No_cell,whole_map,true,false);
         
        command(id,next_move);
      }
    }
    //Herido
    else if(state == "Injured"){
      next_move = bfs(id,"tb",IA,No_cell,Run_range,true,false);
      if(next_move != None){
        (*it).second = "Run";
        celda defa;
        defa.visited = false;
        defa.sig = None;
        defa.dist = 0;
        M_visited m_vis (rows(), vector<celda> (cols(),defa));
        fill_barlog(m_vis);
        command(id, bfs_pillo(id,"n",No_one,Outside,whole_map,true,true,m_vis));
        return;
      }
      if(unit(id).health < wizards_health()){
        next_move = bfs(id,"w",me(),No_cell,whole_map,true,false);
        command(id,next_move);
        return;
      }
      else {
        next_move = bfs(id,"d",me(),No_cell,whole_map,true,false);
         
        command(id,next_move);
        (*it).second = "Healer";
        return;
      }
    }
  }
  
  void change_parameters_dwa(int v_size){
    int treasures = 0;
    for(int i = 0;i < 4;++i){
        treasures += nb_treasures(i);
    }
    if(treasures > No_more_treasures and not changed_strat){
        Next_strat_round = round();
        changed_strat = true;
    }
    if(v_size < 10) {
      Attack_range = 5;
      Attack_range_rage = 8;
    }
    else if(v_size > 40){
      Attack_range = 2;
      Attack_range_rage = 4;
    }
  }  
  
  

  void move_wizards(){
    v wiz = wizards(me());
    int v_size = wiz.size();
    map<int,string>::iterator it;
    for(int i = 0;i < v_size;++i){
      it = wiz_map.find(wiz[i]);
      if(it == wiz_map.end()){
          wiz_map.insert(make_pair(wiz[i],"Healer"));
          it = wiz_map.find(wiz[i]);
      }
      change_state_wiz(it);
    }
  }
  
  void move_dwarfs(){
    v dwa = dwarves(me());
    int v_size = dwa.size();
    change_parameters_dwa(v_size);
    map<int,string>::iterator it;
    for(int i = 0;i < v_size;++i){
      it = dwa_map.find(dwa[i]);
      if(it == dwa_map.end()){
          dwa_map.insert(make_pair(dwa[i],"Idle"));
          it = dwa_map.find(dwa[i]);
      }
      change_state_dwa(it);
    }
  }
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    //search_for_pillo();
    move_wizards();
    move_dwarfs();
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
