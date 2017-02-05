package familydoctor.repository;

import java.util.ArrayList;
import java.util.List;

public class AbstractRepository<E> {

    protected List<E> entities = new ArrayList<E>();

    public long size() {
        return entities.size();
    }

    public List<E> getAll() {
        return entities;
    }
}
