#include <vector>
#include <iostream>


std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) 
{  
  int x = 0, y = 0;
  int size = snail_map[0].size();
  std::cout<<size<<"\n";
  std::cout<<snail_map.size()<<"\n";
  if(size == 0) return {};
  if(size == 1) return {snail_map[0][0]};
  int upper_limit = size-1;
  int lower_limit = 0;
  enum Dir
  {
    FORWARD,
    DOWNWARD,
    BACKWARD,
    UPWARD
  };
  
  Dir dir = FORWARD;
  int counter = 3;
  std::vector<int> res;
  

  for(int i = 0; i<size; i++)
  {
    for(int j = 0; j<size; j++)
    {
      res.push_back(snail_map[y][x]);
      if(dir == FORWARD)
      {
        if(x>upper_limit){x = upper_limit;}
        else{x++;}
        if(x == upper_limit)
        {
            dir = DOWNWARD;
            counter--;
        }
      } 
      else if(dir == DOWNWARD)
      {
        if(y>upper_limit){y = upper_limit;}
        else{y++;}
        if(y == upper_limit)
        {
            dir = BACKWARD;
            counter--;
        }
      } 
      else if(dir == BACKWARD)
      {
        if(x < lower_limit){x = lower_limit;}
        else{x--;}
        if(x == lower_limit)
        {
            dir = UPWARD;
            counter--;
        }
      } 
      else if(dir == UPWARD)
      {
        if(y<lower_limit){y = lower_limit;}
        else{y--;}
        if(y == lower_limit)
        {
            dir = FORWARD;
            counter--;
        }
        if(y<lower_limit)
        {
            std::cout<<"oh no\n";
        }
      }
        if(!counter)
        {
            counter = 4;
            upper_limit--;
            lower_limit++;
        } 

    }
  }
  return res;
  
}

int main(int argc, char const *argv[])
{
    // std::vector<std::vector<int>> snail_map{{1, 2}, {4, 3}};
    

    std::vector<std::vector<int>> snail_map{};

    int counter = 1;
    for(int i =0; i<9; i++)
    {
        std::vector<int> n{};
        for(int j = 0; j<9; j++)
        {
            n.push_back(counter++);
        }
        snail_map.push_back(n);
    }

    auto res = snail(snail_map);

    int n = 0;

    return 0;
}
