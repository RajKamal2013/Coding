package io.datajek.springdata.tennisplayerJpaRepository;

import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface PlayerRepository extends JpaRepository<Player, Integer> {

    public List<Player> findByNationality(String nationality);
}
