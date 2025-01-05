package org.project.flowable;

class MyItem {
    final int id;
    MyItem(int id) {
        this.id = id;
        System.out.println("Constructing MyItem " + id);
    }
}
