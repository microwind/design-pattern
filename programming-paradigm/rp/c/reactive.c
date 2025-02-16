#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Observer
{
  void (*update)(char *);
  struct Observer *next;
} Observer;

typedef struct Subject
{
  char name[50];
  Observer *observers;
} Subject;

void attach(Subject *subject, Observer *observer)
{
  observer->next = subject->observers;
  subject->observers = observer;
}

void detach(Subject *subject, Observer *observer)
{
  Observer **current = &subject->observers;
  while (*current != NULL)
  {
    if (*current == observer)
    {
      *current = (*current)->next;
      break;
    }
    current = &(*current)->next;
  }
}

void notify(Subject *subject, char *message)
{
  Observer *observer = subject->observers;
  while (observer != NULL)
  {
    observer->update(message);
    observer = observer->next;
  }
}

void updateA(char *message)
{
  printf("ObserverA 接到新消息: %s\n", message);
}

void updateB(char *message)
{
  printf("ObserverB 接到新消息: %s\n", message);
}

int main()
{
  Subject subject1 = {"Subject1", NULL};
  Observer observerA = {updateA, NULL};
  Observer observerB = {updateB, NULL};

  attach(&subject1, &observerA);
  attach(&subject1, &observerB);

  notify(&subject1, "发布消息");

  detach(&subject1, &observerA);
  notify(&subject1, "再次发布消息");

  return 0;
}
/**
jarry@Mac c % gcc reactive.c
jarry@Mac c % ./a.out
ObserverB 接到新消息: 发布消息
ObserverA 接到新消息: 发布消息
ObserverB 接到新消息: 再次发布消息
 */